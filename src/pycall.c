//+--------------------------------------------------------------------------+
//| This file is subject to the terms and conditions defined in file         |
//| 'LICENSE.txt', which is part of this source code package.                |
//|--------------------------------------------------------------------------|
//| Copyright (c) 2017 Liang ZOU and contributors                            |
//| See the full list at https://github.com/liangdzou/pycall/contributors    |
//|--------------------------------------------------------------------------|
//| pycall.c -- implementation the APIs in pycall.h                          |
//|                                                                          |
//| Author:   Liang, ZOU                                                     |
//|                                                                          |
//| Purpose:  Implement the APIs in pycall.h                                 |
//+--------------------------------------------------------------------------+

#include <Python.h>
#include <stdarg.h>
#include <string.h>

#include "logger.h"

PyObject * pycall(const char * p_module, const char * p_func,
                  const char * format, ...) {
    Py_Initialize();

    // temp variables
    size_t i;
    long l;
    double d;
    char * str;
    PyObject * py_value;

    // get the module
    PyObject * py_name = PyUnicode_FromString(p_module);
    PyObject * py_module = PyImport_Import(py_name);
    Py_DECREF(py_name);
    if (py_module == NULL) {
        // report error
        PyErr_Print();
        ERROR("failed to load \"%s\"!", p_module);
        return NULL;
    }

    // get the function
    PyObject * py_func = PyObject_GetAttrString(py_module, p_func);
    if (!py_func || !PyCallable_Check(py_func)) {
        if (PyErr_Occurred()) {
            PyErr_Print();
        }
        // release resources
        Py_DECREF(py_module);
        Py_XDECREF(py_func);
        // report error
        ERROR("cannot find function \"%s\"!", p_func);
        return NULL;
    }

    // parse the arguments
    size_t args_num = strlen(format);
    va_list args;
    va_start(args, format);
    PyObject * py_args = PyTuple_New(args_num);
    for (i = 0; i < args_num; ++i) {
        // currently, only int, double, char, and string are supported
        // TODO: support more types
        switch (format[i]) {
            case 'i':
                l = (long)va_arg(args, int);
                py_value = PyLong_FromLong(l);
                break;
            case 'l':
                l = va_arg(args, long);
                py_value = PyLong_FromLong(l);
                break;
            case 'd':
                d = va_arg(args, double);
                py_value = PyFloat_FromDouble(d);
                break;
            case 's':
                str = va_arg(args, char *);
                py_value = PyUnicode_FromString(str);
                break;
            default:
                ERROR("unsupported type (%zu, %c) exists in format!", i, format[i]);
        }
        if (!py_value) {
            // release resources
            Py_DECREF(py_module);
            Py_DECREF(py_func);
            Py_DECREF(py_args);
            va_end(args);
            // report error
            PyErr_Print();
            ERROR("the %zu-th parameter error!", i);
            return NULL;
        }
        PyTuple_SetItem(py_args, i, py_value);
    }
    va_end(args);

    // call the function
    py_value = PyObject_CallObject(py_func, py_args);

    // release resources
    Py_DECREF(py_module);
    Py_DECREF(py_func);
    Py_DECREF(py_args);
    Py_Finalize();

    return py_value;
}
