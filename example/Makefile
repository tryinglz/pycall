PYTHON_CONF=python3-config

CPY_INCLUDE=$(shell $(PYTHON_CONF) --cflags)
CFLAGS+=$(CPY_INCLUDE)
CFLAGS+=-I../include

CPY_LINKER=$(shell $(PYTHON_CONF) --ldflags)
LDFLAGS+=$(CPY_LINKER)

all: example

example: ../src/pycall.o example.o
	clang example.o ../src/libpycall.a $(LDFLAGS) -o example

run: example
	PYTHONPATH=. ./example

clean:
	-find . -name *.o | xargs rm
	-rm -rf __pycache__
	-rm example

.PHONY: run
