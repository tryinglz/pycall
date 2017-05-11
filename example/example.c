//+--------------------------------------------------------------------------+
//| This file is subject to the terms and conditions defined in file         |
//| 'LICENSE.txt', which is part of this source code package.                |
//|--------------------------------------------------------------------------|
//| Copyright (c) 2017 Liang ZOU and contributors                            |
//| See the full list at https://github.com/liangdzou/pycall/contributors    |
//|--------------------------------------------------------------------------|
//| test.c -- a test program that uses pycall                                |
//|                                                                          |
//| Author:   Liang, ZOU                                                     |
//|                                                                          |
//| Purpose:  Show how to use pycall                                         |
//+--------------------------------------------------------------------------+

#include <stdio.h>

#include "pycall.h"
#include "logger.h"

int main(int argc, char *argv[]) {
    SHOW("Pass this message.");
    PyObject * result = pycall("example", "testFunc", "s", "Pass this message.");
    int return_val = PyLong_AsLong(result);
    SHOW("C: [Result] is: %d\n", return_val);
    return 0;
}
