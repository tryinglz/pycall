# Pycall : C API for python functions #

Pycall is an open-source C API for python functions that provides an easy way to call python functions directly in C/C++.

## Get Started with Pycall ##

In the following, we use the folder "PYCALL_HOME" to present the repo folder of
pycall. For instance, if the git repo is put under "/home/liang/", then
"PYCALL_HOME" represents "/home/liang/pycall".

### Build it ###

Pycall is built as follows, and resulted static library is
"PYCALL_HOME/src/libpycall.a".

```bash
$ cd PYCALL_HOME
$ make
```

The resulted static library is "PYCALL_HOME/src/libpycall.a"

Optionally, you can run the tests by running

```bash
$ make test
```

Currently, we have not implemented enough tests for the project yet.

### Try example ###

You can try the example to see how Pycall is used.

```bash
$ cd PYCALL_HOME/example
$ make
$ make run
```

As a result, logs are shown. You can read the logs with the source code to find
out how Pycall works.

## Using Pycall ##

Currently, we only support one powerful API

```c
PyObject * pycall(const char * py_module, const char * py_func,
                  const char * format, ...);
```

where "py_module" and "py_func" are the name of module and function
accordingly, "format" states the type of the following arguments, and "..."
presents a list of variable length arguments for python function "py_func".

## Contributing ##

Pycall is currently under active development. You can help us in multiple ways,
such as bug report, feature requirement, test case contribution, or comment.

## Licenses ##

Pycall is released under the [MIT license](LICENSE).
