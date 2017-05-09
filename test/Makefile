all: test

CFLAGS+=-I../include

test_build: ../src/pycall.o test.o
	clang ../src/pycall.o test.o $(LDFLAGS) -o test

test: test_build
	PYTHONPATH=. ./test

clean:
	-find . -name *.o | xargs rm
	-rm -rf __pycache__
	-rm test

.PHONY: test
