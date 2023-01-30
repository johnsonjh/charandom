/*
 * vim: filetype=c:tabstop=4:ai:expandtab
 * SPDX-License-Identifier: ISC
 * scspell-id: e8c15666-a0f2-11ed-a637-80ee73e9b8e7
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

#ifndef ___CHARANDOM_H___
# define ___CHARANDOM_H___  1

/*
 * ChaCha-based random number generator derived from OpenBSD arc4random.
 * This cryptographic random generator passes NIST-SP-800-22 (Rev 1).
 */

# include <stdint.h>
# include <sys/types.h>

typedef unsigned char u8;
typedef uint32_t     u32;

struct chacha_ctx
{
  uint32_t input[16];
};

typedef struct chacha_ctx chacha_ctx;

# define U8C(v)         (v ## U)
# define U32C(v)        (v ## U)

# define U8V(v)         ( (u8)( v ) &  U8C(0xFF))
# define U32V(v)        ((u32)( v ) & U32C(0xFFFFFFFF))

# define ROTL32(v, n)   ( U32V(( v ) << ( n )) | \
                              (( v ) >> ( 32 - ( n ))))

# define U8TO32_LITTLE(p)      \
  (((u32)(( p )[0] ))        | \
   ((u32)(( p )[1] ) <<  8 ) | \
   ((u32)(( p )[2] ) << 16 ) | \
   ((u32)(( p )[3] ) << 24 ))

# define U32TO8_LITTLE(p, v)        \
  do                                \
    {                               \
      ( p )[0]  = U8V(( v ));       \
      ( p )[1]  = U8V(( v ) >>  8); \
      ( p )[2]  = U8V(( v ) >> 16); \
      ( p )[3]  = U8V(( v ) >> 24); \
    }                               \
  while (0)

# define ROTATE(v, c)   ( ROTL32(v, c))
# define XOR(v, w)      (( v ) ^ ( w ))
# define PLUS(v, w)     ( U32V ( ( v ) + ( w )))
# define PLUSONE(v)     ( PLUS ( ( v ), 1))

# define QUARTERROUND(a, b, c, d) \
  a  = PLUS(a, b);                \
  d  = ROTATE(XOR(d, a), 16);     \
  c  = PLUS(c, d);                \
  b  = ROTATE(XOR(b, c), 12);     \
  a  = PLUS(a, b);                \
  d  = ROTATE(XOR(d, a),  8);     \
  c  = PLUS(c, d);                \
  b  = ROTATE(XOR(b, c),  7);

static const char  sigma[16]  = "expand 32-byte k";
static const char  tau[16]    = "expand 16-byte k";

int cha_getentropy(void *buf, size_t n);

static inline void
chacha_keysetup(chacha_ctx *x, const u8 *k, u32 kbits, u32 ivbits)
{
  const char *constants;

  (void)ivbits;

  x->input[4]  = U8TO32_LITTLE(k +  0);
  x->input[5]  = U8TO32_LITTLE(k +  4);
  x->input[6]  = U8TO32_LITTLE(k +  8);
  x->input[7]  = U8TO32_LITTLE(k + 12);

  if (kbits == 256)
    {
      k         += 16;
      constants  = sigma;
    }
  else
    {
      constants = tau;
    }

  x->input [8]  = U8TO32_LITTLE(k +  0);
  x->input [9]  = U8TO32_LITTLE(k +  4);
  x->input[10]  = U8TO32_LITTLE(k +  8);
  x->input[11]  = U8TO32_LITTLE(k + 12);
  x->input [0]  = U8TO32_LITTLE(constants +  0);
  x->input [1]  = U8TO32_LITTLE(constants +  4);
  x->input [2]  = U8TO32_LITTLE(constants +  8);
  x->input [3]  = U8TO32_LITTLE(constants + 12);
}

static inline void
chacha_ivsetup(chacha_ctx *x, const u8 *iv)
{
  x->input[12]  = 0;
  x->input[13]  = 0;
  x->input[14]  = U8TO32_LITTLE(iv + 0);
  x->input[15]  = U8TO32_LITTLE(iv + 4);
}

static inline void
chacha_encrypt_bytes(chacha_ctx *x, const u8 *m, u8 *c, u32 bytes)
{
  u32    x0, x1,  x2,  x3,  x4,  x5,  x6, x7,
         x8, x9, x10, x11, x12, x13, x14, x15;
  u32    j0, j1,  j2,  j3,  j4,  j5,  j6, j7,
         j8, j9, j10, j11, j12, j13, j14, j15;
  u8 *   ctarget = NULL;
  u8     tmp[64];
  u_int  i;

  if (!bytes)
    {
      return;
    }

  j0   = x->input [0];
  j1   = x->input [1];
  j2   = x->input [2];
  j3   = x->input [3];
  j4   = x->input [4];
  j5   = x->input [5];
  j6   = x->input [6];
  j7   = x->input [7];
  j8   = x->input [8];
  j9   = x->input [9];
  j10  = x->input[10];
  j11  = x->input[11];
  j12  = x->input[12];
  j13  = x->input[13];
  j14  = x->input[14];
  j15  = x->input[15];

  for (;;)
    {
      if (bytes < 64)
        {
          for (i = 0; i < bytes; ++i)
            {
              tmp[i] = m[i];
            }

          m        = tmp;
          ctarget  = c;
          c        = tmp;
        }

      x0   = j0;
      x1   = j1;
      x2   = j2;
      x3   = j3;
      x4   = j4;
      x5   = j5;
      x6   = j6;
      x7   = j7;
      x8   = j8;
      x9   = j9;
      x10  = j10;
      x11  = j11;
      x12  = j12;
      x13  = j13;
      x14  = j14;
      x15  = j15;

      for (i = 20; i > 0; i -= 2)
        {
          QUARTERROUND(x0, x4,  x8, x12)
          QUARTERROUND(x1, x5,  x9, x13)
          QUARTERROUND(x2, x6, x10, x14)
          QUARTERROUND(x3, x7, x11, x15)
          QUARTERROUND(x0, x5, x10, x15)
          QUARTERROUND(x1, x6, x11, x12)
          QUARTERROUND(x2, x7,  x8, x13)
          QUARTERROUND(x3, x4,  x9, x14)
        }

      x0   = PLUS(x0,  j0);
      x1   = PLUS(x1,  j1);
      x2   = PLUS(x2,  j2);
      x3   = PLUS(x3,  j3);
      x4   = PLUS(x4,  j4);
      x5   = PLUS(x5,  j5);
      x6   = PLUS(x6,  j6);
      x7   = PLUS(x7,  j7);
      x8   = PLUS(x8,  j8);
      x9   = PLUS(x9,  j9);
      x10  = PLUS(x10, j10);
      x11  = PLUS(x11, j11);
      x12  = PLUS(x12, j12);
      x13  = PLUS(x13, j13);
      x14  = PLUS(x14, j14);
      x15  = PLUS(x15, j15);

# ifndef KEYSTREAM_ONLY
      x0   = XOR(x0,  U8TO32_LITTLE(m +  0));
      x1   = XOR(x1,  U8TO32_LITTLE(m +  4));
      x2   = XOR(x2,  U8TO32_LITTLE(m +  8));
      x3   = XOR(x3,  U8TO32_LITTLE(m + 12));
      x4   = XOR(x4,  U8TO32_LITTLE(m + 16));
      x5   = XOR(x5,  U8TO32_LITTLE(m + 20));
      x6   = XOR(x6,  U8TO32_LITTLE(m + 24));
      x7   = XOR(x7,  U8TO32_LITTLE(m + 28));
      x8   = XOR(x8,  U8TO32_LITTLE(m + 32));
      x9   = XOR(x9,  U8TO32_LITTLE(m + 36));
      x10  = XOR(x10, U8TO32_LITTLE(m + 40));
      x11  = XOR(x11, U8TO32_LITTLE(m + 44));
      x12  = XOR(x12, U8TO32_LITTLE(m + 48));
      x13  = XOR(x13, U8TO32_LITTLE(m + 52));
      x14  = XOR(x14, U8TO32_LITTLE(m + 56));
      x15  = XOR(x15, U8TO32_LITTLE(m + 60));
# endif /* ifndef KEYSTREAM_ONLY */

      j12 = PLUSONE(j12);
      if (!j12)
        {
          j13 = PLUSONE(j13);
        }

      U32TO8_LITTLE(c +  0,  x0);
      U32TO8_LITTLE(c +  4,  x1);
      U32TO8_LITTLE(c +  8,  x2);
      U32TO8_LITTLE(c + 12,  x3);
      U32TO8_LITTLE(c + 16,  x4);
      U32TO8_LITTLE(c + 20,  x5);
      U32TO8_LITTLE(c + 24,  x6);
      U32TO8_LITTLE(c + 28,  x7);
      U32TO8_LITTLE(c + 32,  x8);
      U32TO8_LITTLE(c + 36,  x9);
      U32TO8_LITTLE(c + 40, x10);
      U32TO8_LITTLE(c + 44, x11);
      U32TO8_LITTLE(c + 48, x12);
      U32TO8_LITTLE(c + 52, x13);
      U32TO8_LITTLE(c + 56, x14);
      U32TO8_LITTLE(c + 60, x15);

      if (bytes <= 64)
        {
          if (bytes < 64)
            {
              for (i = 0; i < bytes; ++i)
                {
                  ctarget[i] = c[i];
                }
            }

          x->input[12]  = j12;
          x->input[13]  = j13;
          return;
        }

      bytes  -= 64;
      c      += 64;
# ifndef KEYSTREAM_ONLY
      m      += 64;
# endif /* ifndef KEYSTREAM_ONLY */
    }
}

/*
 * ChaCha20 parameters
 */

# define ARC4R_BLOCKSZ   64
# define ARC4R_KEYSZ     32
# define ARC4R_IVSZ       8

/*
 * Adjust this to change amount of keystream buffer to hold in the
 * rand state (in units of cipher basic blocks). Must be greater than 4.
 */

# define __RSBLOCKS    16

# define __max(a, b)   (( a ) > ( b ) ? ( a ) : ( b ))
# define __RSBUFSZ     ( __RSBLOCKS * __max(ARC4R_BLOCKSZ, ARC4R_BLOCKSZ))

/*
 * Fetch n bytes of entropy from the system and fill the output buffer
 */

typedef int (*crypto_rand_entropy_t) (void *, size_t);

/*
 * Random generator state
 */

struct crypto_rand_state
{
  uint8_t buf[__RSBUFSZ];   /* rand bytes        */
  uint8_t *ptr;             /* current pointer   */
  size_t count;             /* bytes till reseed */
  union
  {
    chacha_ctx chacha;      /* ChaCha20 context */
  };
  crypto_rand_entropy_t entropy;

  /*
   * Internal virtual funcs
   */

  /*
   * Encrypt buf with the current key in CTR mode
   */

  void (*crypt_buf) (struct crypto_rand_state *);

  /*
   * Re-initialize the cipher state with random keys
   */

  void (*crypt_reinit) (struct crypto_rand_state *);

  /*
   * Regenerate new keys and update crypto-rand state
   */

  void (*crypt_rekey) (struct crypto_rand_state *);
};
typedef struct crypto_rand_state crypto_rand_state;

# define CRYPTO_RAND_CHACHA20  2

/*
 * Initialize the random generator state using the given cipher
 * algo (must be one of CRYPTO_RAND_CHACHA20).
 *
 * Use the supplied function to fetch entropy when we need it.
 */

extern int crypto_rand_init(crypto_rand_state *, int algo,
                            crypto_rand_entropy_t entropy);

/*
 * Fill a buffer with random data
 */

extern void crypto_rand_buf(crypto_rand_state *, void *buf, size_t nbytes);

# ifdef WANT_CHARDOUBLE

/*
 * Return a uniform random uint64
 */

extern uint64_t crypto_rand_uniform64_bounded(crypto_rand_state *,
                                              uint64_t upper_bound);

/*
 * Return a uniform random uint32
 */

extern uint32_t crypto_rand_uniform32_bounded(crypto_rand_state *,
                                              uint32_t upper_bound);

/*
 * Return a uniform uint64
 */

static inline uint64_t
crypto_rand_uniform64(crypto_rand_state *st)
{
  uint64_t z = 0;

  crypto_rand_buf(st, &z, sizeof z);
  return z;
}

/*
 * Return a uniform uint32
 */

static inline uint32_t
crypto_rand_uniform32(crypto_rand_state *st)
{
  uint32_t z = 0;

  crypto_rand_buf(st, &z, sizeof z);
  return z;
}

/*
 * Return a random float64 in the range [0.0, 1.0].
 *
 * Notes
 * =====
 *
 * IEEE 754 double precision format:
 *   bit 63    :  sign
 *   bit 62-52 :  exponent (11 bits)
 *   bit 51-0  :  fraction
 *
 * So, when we set sign = 0 and exponent = 0xfff, then the format
 * represents a normalized number in the range [1, 2].
 *
 * So, if we can manage to fill the 52 bits with random bits, we will have
 * a normalized random number in the range [1, 2]. Then, we subtract 1.0
 * and voila - we have a random number in the range [0, 1.0].
 */

  static inline double
  crypto_rand_double(crypto_rand_state *st)
  {
    union
    {
      double d;
      uint64_t v;
    } un;

    uint64_t  r = crypto_rand_uniform64(st) & ~0xfff0000000000000;

    un.d  = 1.0;
    un.v |= r;

    return un.d - 1.0;
  }

# endif /* ifdef WANT_CHADOUBLE */
#endif /* ifndef ___CHARANDOM_H___ */
