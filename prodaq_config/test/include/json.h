/**
 * @file json.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __JSON__H__
#define __JSON__H__

#include "cJSON.h"

#define JSON_PATH "../../../prodaq_config/test/json"

cJSON* json_read_file(const char* filename);

#endif  //!__JSON__H__