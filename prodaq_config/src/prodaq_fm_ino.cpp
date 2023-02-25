/**
 * @file prodaq_fm.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "prodaq_config.h"

#if defined(__ARDUINO__)

#include "prodaq_fm.h"
#include "prodaq_err.h"
#include <stdio.h>
#include <string.h>

#if defined(ESP8266)
#include <LittleFS.h>
#define FS LittleFS
#define FILE_WRITE "w"
#define FILE_READ "r"
#elif defined(ESP32)
#include <SPIFFS.h>
#define FS SPIFFS
#define FILE_WRITE "w"
#define FILE_READ "r"
#else
#include <SD.h>
#define FS SD
#endif

prodaq_err_t prodaq_fm_save(void *data, size_t size, const char *filename)
{
  File file = FS.open(filename, FILE_WRITE);
  if (!file)
  {
    printf("PRODAQ_ERR_FILE_OPEN_FAILED\n");
    return PRODAQ_ERR_FILE_OPEN_FAILED;
  }
  if (file.write((uint8_t *)data, size) != size)
  {
    file.close();
    printf("PRODAQ_ERR_WRITE_OPERATION_FAILED\n");
    return PRODAQ_ERR_WRITE_OPERATION_FAILED;
  }
  file.close();
  printf("prodaq_fm_save OK\n");
  return PRODAQ_OK;
}

prodaq_err_t prodaq_fm_load(void *data, size_t size, const char *filename)
{
  File file = FS.open(filename, FILE_READ);
  if (!file)
  {
    printf("PRODAQ_ERR_FILE_OPEN_FAILED\n");
    return PRODAQ_ERR_FILE_OPEN_FAILED;
  }
  if (file.read((uint8_t *)data, size) != size)
  {
    file.close();
    printf("PRODAQ_ERR_READ_OPERATION_FAILED\n");
    return PRODAQ_ERR_READ_OPERATION_FAILED;
  }
  file.close();
  printf("prodaq_fm_load OK\n");
  return PRODAQ_OK;
}

#endif //! PRODAQ_TARGET_INO