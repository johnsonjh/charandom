CC     ?= gcc
CFLAGS  = -O3 -march=native -flto=auto -Wall -I.
LDFLAGS = -lpthread -flto=auto
objs    = cryptorand.o error.o
tests   = t_arc4rand

.PHONY: all
all: $(tests)

t_arc4rand: t_arc4rand.o $(objs)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	-rm -f $(objs) *.o $(tests)
