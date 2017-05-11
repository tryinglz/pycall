PYTHON_CONF=python3-config

CPY_INCLUDE=$(shell $(PYTHON_CONF) --cflags)
CFLAGS+=$(CPY_INCLUDE)
CFLAGS+=-I../include

CPY_LINKER=$(shell $(PYTHON_CONF) --ldflags)
LDFLAGS+=$(CPY_LINKER)

export CC=clang

all:
	+$(MAKE) -C src CFLAGS="$(CFLAGS)"

test:
	+$(MAKE) -C test test CFLAGS="$(CFLAGS)" LDFLAGS="$(LDFLAGS)"

clean:
	+$(MAKE) -C src clean
	+$(MAKE) -C test clean

.PHONY: test
