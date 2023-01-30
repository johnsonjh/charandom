#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#include "charandom.h"

int
main(int argc, const char *argv[])
{
  crypto_rand_state  st;

  if (crypto_rand_init(&st, CRYPTO_RAND_CHACHA20, cha_getentropy))
    {
      (void)fprintf(stderr, "\r\nInitialization failed. Aborting!\r\n");
      abort();
    }

  int n = 1024;

  if (argc > 1)
    {
      int z = atoi(argv[1]);
      if (z < 0)
        {
          (void)fprintf(stderr, "ERROR: Invalid size %s\r\n", argv[1]);
          exit(1);
        }
      if (z == 0)
        {
          z = 1048576;
        }

      n = z;
    }

  uint8_t *buf = malloc(n);
  if (buf == NULL)
    {
      (void)fprintf(stderr, "\r\nOut of memory. Aborting!\r\n");
      abort();
    }

loop:
  crypto_rand_buf(&st, buf, n);
  fwrite(buf, 1, n, stdout);

  if (n == 1048576)
    goto loop;

  free(buf);
  buf = NULL;
  return 0;
}
