/**
 * @file datalogger_config.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __DATALOGGER_CONFIG__H__
#define __DATALOGGER_CONFIG__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <inttypes.h>
#include "prodaq_json.h"

typedef struct
{
    uint32_t id;
    uint32_t interval;
    char file_path[32];
    uint16_t file_max_size;
} datalogger_config_t;

/**
 * @brief Serialize an datalogger_config_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t datalogger_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(datalogger_config_t));

/**
 * @brief Deserialize an datalogger_config_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t datalogger_config_to_json(PRODAQ_TO_JSON_PARAMETERS(datalogger_config_t));

#ifdef __cplusplus
}
#endif

#endif  //!__DATALOGGER_CONFIG__H__