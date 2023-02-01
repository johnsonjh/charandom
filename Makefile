# vim: filetype=make:tabstop=4:ai:noexpandtab
# SPDX-License-Identifier: ISC
# scspell-id: 3ac313ae-a0f3-11ed-ac05-80ee73e9b8e7
# Copyright (c) 2023 The DPS8M Development Team

##############################################################################

CC     ?= gcc
CFLAGS  = -O3 -march=native -flto=auto -Wall -I.
LDFLAGS = -lpthread -flto=auto
tests   = test

##############################################################################

.PHONY: all
all: $(tests)

##############################################################################

test: test.o
	$(CC) -o $@ $^ $(LDFLAGS)

##############################################################################

.PHONY: clean
clean:
	-rm -f *.o $(tests)

##############################################################################
