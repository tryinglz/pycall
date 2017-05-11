all: test

test_build: ../src/pycall.o test.o
	clang ../src/pycall.o test.o $(LDFLAGS) -o test1

test: test_build
	PYTHONPATH=. ./test1

clean:
	-find . -name *.o | xargs rm
	-rm -rf __pycache__
	-rm test1

.PHONY: test
