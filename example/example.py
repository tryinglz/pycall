# -*- coding: utf-8 -*-

#+---------------------------------------------------------------------------+
#| This file is subject to the terms and conditions defined in file          |
#| 'LICENSE.txt', which is part of this source code package.                 |
#|                                                                           |
#|---------------------------------------------------------------------------|
#| Copyright (c) 2017 Liang ZOU and contributors                             |
#| See the full list at https://github.com/liangdzou/pycall/contributors     |
#|                                                                           |
#|---------------------------------------------------------------------------|
#| test.py  -- a test program that uses pycall                               |
#|                                                                           |
#| Author:   Liang, ZOU                                                      |
#|                                                                           |
#| Purpose:  Show how to use pycall                                          |
#|                                                                           |
#+---------------------------------------------------------------------------+

def testFunc(message):
  print("Python: python function testFunc is executed!")
  print("Python: The message is \"", message, "\"")
  result = 2017
  print("Python: The result should be \"", result, "\"")
  return result
