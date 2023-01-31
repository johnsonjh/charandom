/*
 * vim: filetype=c:tabstop=4:ai:expandtab
 * SPDX-License-Identifier: ISC
 * scspell-id: 08bd080c-a0f2-11ed-b5f7-80ee73e9b8e7
 *
 * ---------------------------------------------------------------------------
 *
 * Copyright (c) 1996 David Mazieres <dm@uun.org>
 * Copyright (c) 2008 Damien Miller <djm@openbsd.org>
 * Copyright (c) 2013 Markus Friedl <markus@openbsd.org>
 * Copyright (c) 2014 Theo de Raadt <deraadt@openbsd.org>
 * Copyright (c) 2015-2021 Sudhi Herle <sudhi@herle.net>
 * Copyright (c) 2021 Jeffrey H. Johnson <trnsz@pobox.com>
 * Copyright (c) 2023 The DPS8M Development Team
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * ---------------------------------------------------------------------------
 */

/*
 * ChaCha-based random number generator derived from OpenBSD arc4random.
 * This cryptographic random generator passes NIST-SP-800-22 (Rev 1).
 */

#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "charandom.h"

static int
cha_randopen(const char *name)
{
  int fd = open(name, O_RDONLY);

  if (fd < 0)
    {
      (void)fprintf(stderr,
        "\r\nFATAL: Unable to access %s: %s.\r\n",
        name, strerror(errno));
      abort();
    }

  return fd;
}

int
cha_getentropy(void *buf, size_t n)
{
  static int  fd  = -1;
  uint8_t *   b   = (uint8_t *)buf;

  if (fd < 0)
    {
      fd = cha_randopen("/dev/urandom");
    }

  while (n > 0)
    {
      ssize_t m = (read)( fd, b, n );

      if (m < 0)
        {
          if (errno == EINTR)
            {
              continue;
            }

          (void)fprintf(stderr,
            "\r\nFATAL: Failure reading: %s.\r\n",
            strerror(errno));
          abort();
        }

      b  += m;
      n  -= m;
    }

  return 0;
}

#define minimum(a, b)      ( ( a ) < ( b ) ? ( a ) : ( b ) )

#define RAND_RESEED_BYTES  ( 128 * 1024 )

static inline void
_rs_rekey(crypto_rand_state *st, uint8_t *dat, size_t datlen)
{
  st->crypt_buf(st);

  /*
   * Mix in optional user provided data
   */

  if (dat)
    {
      size_t i, m;

      m = minimum(datlen, sizeof st->buf);
      for (i = 0; i < m; i++)
        {
          st->buf[i] ^= dat[i];
        }

      (void)memset(dat, 0, datlen);
    }

  /*
   * Immediately re-init for backtracking resistance
   */

  st->crypt_reinit(st);
}

/*
 * Stir the pot by rekeying
 */

static void
_rs_stir(crypto_rand_state *st)
{
  st->crypt_rekey(st);

  /*
   * Invalidate rand buf
   */

  (void)memset(st->buf, 0, sizeof st->buf);
  st->ptr    = st->buf + sizeof st->buf;
  st->count  = RAND_RESEED_BYTES;
}

/*
 * Maybe stir the pot
 */

static inline void
_rs_stir_if_needed(crypto_rand_state *st, size_t len)
{
  if (st->count <= len)
    {
      _rs_stir(st);
    }

  /*
   * We explicitly don't worry about underflow because
   * we want this to be somewhat random after we stir.
   */

  st->count -= len;
}


static inline void
__chacha_key_setup(crypto_rand_state *st, uint8_t *key, uint8_t *iv)
{
  chacha_keysetup (&st->chacha, key, ARC4R_KEYSZ * 8, 0);
  chacha_ivsetup  (&st->chacha, iv);
}

static void
__chacha_crypt_buf(crypto_rand_state *st)
{
  chacha_encrypt_bytes(&st->chacha, st->buf, st->buf, sizeof st->buf);
}

static void
__chacha_rekey(crypto_rand_state *st)
{
  uint8_t  rnd[ARC4R_KEYSZ + ARC4R_IVSZ];

  (void)(*st->entropy)(rnd, sizeof rnd);

  _rs_rekey(st, rnd, sizeof ( rnd ));
}

static void
__chacha_reinit(crypto_rand_state *st)
{
  uint8_t * key  = &st->buf[0];
  uint8_t * iv   = key + ARC4R_KEYSZ;

  __chacha_key_setup(st, key, iv);

  (void)memset(key, 0, ARC4R_KEYSZ + ARC4R_IVSZ); /* //-V1086 */
  st->ptr = st->buf + ( ARC4R_KEYSZ + ARC4R_IVSZ );
}

static inline void
__chacha_init(crypto_rand_state *st)
{
  uint8_t rnd[ARC4R_KEYSZ + ARC4R_IVSZ] = { (uint8_t)0 };

  __chacha_key_setup(st, rnd, rnd + ARC4R_KEYSZ);
}

static void
_chacha_setup(crypto_rand_state *st)
{
  st->crypt_buf     = __chacha_crypt_buf;
  st->crypt_reinit  = __chacha_reinit;
  st->crypt_rekey   = __chacha_rekey;
}

/*
 * External API
 */

int
crypto_rand_init(crypto_rand_state *st, int algo,
                 crypto_rand_entropy_t entropy)
{
  if (!entropy)
    {
      return -EINVAL;
    }

  (void)memset(st, 0, sizeof *st);
  st->entropy = entropy;

  switch (algo)
    {
    case CRYPTO_RAND_CHACHA20:
      _chacha_setup(st);
      __chacha_init(st);
      break;

    default:
      return -EINVAL;
    }

  /*
   * When we startup, st->buf is zero so, we are
   * encrypting a zero-buf with a random key & IV.
   */

  _rs_rekey(st, 0, 0);
  return 0;
}

/*
 * Fill buffer with randomness
 */

void
crypto_rand_buf(crypto_rand_state *st, void *buf, size_t n)
{
  uint8_t *end = st->buf + sizeof st->buf;

  _rs_stir_if_needed(st, n);
  while (n > 0)
    {
      size_t avail = end - st->ptr;
      if (avail > 0)
        {
          size_t m = minimum(n, avail);

          if (!memcpy(buf, st->ptr, m))
            {
              (void)fprintf(stderr, "Out of memory. Aborting!\r\n");
              abort();
            }

          buf      += m;
          n        -= m;
          st->ptr  += m;
        }
      else
        {
          _rs_rekey(st, NULL, 0);
        }
    }
}

#ifdef WANT_CHADOUBLE

/*
 * Calculate a uniformly distributed random number less than
 * upper_bound avoiding "modulo bias".
 *
 * Uniformity is achieved by generating new random numbers until
 * the one returned is outside the range [0, 2**32 % upper_bound].
 * This guarantees the selected random number will be inside
 * [2**32 % upper_bound, 2**32] which maps back to [0, upper_bound]
 * after reduction modulo upper_bound.
 */

uint32_t
crypto_rand_uniform32_bounded(crypto_rand_state *st, uint32_t upper_bound)
{
  uint32_t r, min;

  if (upper_bound < 2)
    {
      return 0;
    }

  /*
   * 2**32 % x == (2**32 - x) % x
   */

  min = -upper_bound % upper_bound;

  /*
   * This could theoretically loop forever but each retry has
   * p > 0.5 (worst case, usually far better) of selecting a
   * number inside the range we need, so it should rarely need
   * to re-roll.
   */

  for (;;)
    {
      r = crypto_rand_uniform32(st);
      if (r >= min)
        {
          break;
        }
    }

  return r % upper_bound;
}

/*
 * Calculate a uniformly distributed random number less than
 * upper_bound avoiding "modulo bias".
 *
 * Uniformity is achieved by generating new random numbers until
 * the one returned is outside the range [0, 2**64 % upper_bound].
 * This guarantees the selected random number will be inside
 * [2**64 % upper_bound, 2**64] which maps back to [0, upper_bound]
 * after reduction modulo upper_bound.
 */

uint64_t
crypto_rand_uniform64_bounded(crypto_rand_state *st, uint64_t upper_bound)
{
  uint64_t r, min;

  if (upper_bound < 2)
    {
      return 0;
    }

  /*
   * 2**64 % x == (2**64 - x) % x
   */

  min = -upper_bound % upper_bound;

  /*
   * This could theoretically loop forever but each retry has
   * p > 0.5 (worst case, usually far better) of selecting a
   * number inside the range we need, so it should rarely need
   * to re-roll.
   */

  for (;;)
    {
      r = crypto_rand_uniform64(st);
      if (r >= min)
        {
          break;
        }
    }

  return r % upper_bound;
}

#endif /* ifdef WANT_CHADOUBLE */
