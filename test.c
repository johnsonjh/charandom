/*
 * vim: filetype=c:tabstop=4:ai:expandtab
 * SPDX-License-Identifier: ISC
 * scspell-id: 5d0569de-a0f3-11ed-9380-80ee73e9b8e7
 * Copyright (c) 2023 The DPS8M Development Team
 */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "charandom.h"

int
main(int argc, const char *argv[])
{
  crypto_rand_state  st;

  if (crypto_rand_init(&st, CRYPTO_RAND_CHACHA20, cha_getentropy))
    {
      (void)fprintf(stderr, "FATAL: Initialization failed. Aborting!\r\n");
      abort();
    }

  int n = 1024;

  if (argc > 1)
    {
      int z = atoi(argv[1]);
      if (z < 0)
        {
          (void)fprintf(stderr, "ERROR: Invalid size %s.\r\n", argv[1]);
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
      (void)fprintf(stderr, "FATAL: Out of memory. Aborting!\r\n");
      abort();
    }

loop:
  crypto_rand_buf(&st, buf, n);
  int w = fwrite(buf, 1, n, stdout);
  if (w != n)
    {
      (void)fprintf(stderr, "ERROR: Short write (%d out of %d bytes).\r\n",
                    w, n);
      free(buf);
      buf = NULL;
      return 0;
    }

  if (n == 1048576)
    goto loop;

  free(buf);
  buf = NULL;
  return 0;
}
