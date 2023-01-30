CC     ?= gcc
CFLAGS  = -O3 -march=native -flto=auto -Wall -I.
LDFLAGS = -lpthread -flto=auto
objs    = charandom.o
tests   = test

.PHONY: all
all: $(tests)

test: test.o $(objs)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	-rm -f $(objs) *.o $(tests)
