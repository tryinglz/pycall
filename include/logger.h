//+--------------------------------------------------------------------------+
//| This file is subject to the terms and conditions defined in file         |
//| 'LICENSE.txt', which is part of this source code package.                |
//|--------------------------------------------------------------------------|
//| Copyright (c) 2017 Liang ZOU and contributors                            |
//| See the full list at https://github.com/liangdzou/pycall/contributors    |
//|--------------------------------------------------------------------------|
//| logger.h -- macros for showing logs                                      |
//|                                                                          |
//| Author:   Liang, ZOU                                                     |
//|                                                                          |
//| Purpose:  Implement the macros for show logs                             |
//+--------------------------------------------------------------------------+

#define PRINT(en, fmt, ...)                                                    \
  if (en) printf("%s:%d: " fmt "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)

#define ENABLE_INFO       1
#define ENABLE_WARNING    1
#define ENABLE_ERROR      1

#define SHOW(fmt, ...) PRINT(1, "[SHOW]\t" fmt, ##__VA_ARGS__)

#define INFO(fmt, ...) PRINT(ENABLE_INFO, "[INFO]\t" fmt, ##__VA_ARGS__)
#define WARNING(fmt, ...) PRINT(ENABLE_WARNING, "[WARNING]\t" fmt, ##__VA_ARGS__)
#define ERROR(fmt, ...) PRINT(ENABLE_ERROR, "[ERROR]\t" fmt, ##__VA_ARGS__)
