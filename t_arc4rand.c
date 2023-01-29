#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#include "cryptorand.h"

extern void error(int doexit, int err, const char *fmt, ...);

int
main(int argc, const char *argv[])
{
  crypto_rand_state  st;

  if (crypto_rand_init(&st, CRYPTO_RAND_CHACHA20, getentropy))
    {
      error(1, 0, "unable to init");
    }

  int n = 1024;

  if (argc > 1)
    {
      int z = atoi(argv[1]);
      if (z <= 0)
        {
          error(1, 0, "invalid size %s", argv[1]);
        }

      n = z;
    }

  uint8_t *buf = malloc(n);
  if (buf == NULL)
    {
      fprintf(stderr, "\r\nOut of memory! Aborting.\r\n");
      abort();
    }

  crypto_rand_buf(&st, buf, n);

  fwrite(buf, 1, n, stdout);
  free(buf);
  buf = NULL;
  return 0;
}
