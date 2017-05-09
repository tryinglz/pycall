export CPY_INCLUDE=$(shell python3-config --cflags)
export CPY_LINKER=$(shell python3-config --ldflags)

export CFLAGS+=$(CPY_INCLUDE)
export LDFLAGS+=$(CPY_LINKER)

export CC=clang

all:
	+$(MAKE) -C src

test:
	+$(MAKE) -C test test

clean:
	+$(MAKE) -C src clean
	+$(MAKE) -C test clean

.PHONY: test
