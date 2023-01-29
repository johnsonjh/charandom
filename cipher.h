#ifndef __CIPHER_H__5071821__
# define __CIPHER_H__5071821__  1

# include "chacha_private.h"
# include "cryptorand.h"

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

  _rs_rekey(st, rnd, sizeof ( rnd ));
}

static void
__chacha_reinit(crypto_rand_state *st)
{
  uint8_t * key  = &st->buf[0];
  uint8_t * iv   = key + ARC4R_KEYSZ;

  __chacha_key_setup(st, key, iv);

  memset(key, 0, ARC4R_KEYSZ + ARC4R_IVSZ); /* //-V1086 */
  st->ptr = st->buf + ( ARC4R_KEYSZ + ARC4R_IVSZ );
}

static inline void
__chacha_init(crypto_rand_state *st)
{
  uint8_t rnd[ARC4R_KEYSZ + ARC4R_IVSZ];

  __chacha_key_setup(st, rnd, rnd + ARC4R_KEYSZ);
}
#endif /* __CIPHER_H__5071821__ */
