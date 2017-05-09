export CPY_INCLUDE=$(shell python3-config --cflags)
export CFLAGS+=$(CPY_INCLUDE)

export CC=clang

all:
	+$(MAKE) -C src

test:
	+$(MAKE) -C test test

clean:
	+$(MAKE) -C src clean
	+$(MAKE) -C test clean

.PHONY: test
