/**
 * @file gateway_config.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __GATEWAY_CONFIG__H__
#define __GATEWAY_CONFIG__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <inttypes.h>
#include <stdbool.h>
#include "prodaq_json.h"

typedef enum
{
    GATEWAY_INVALID_FORMAT,
    GATEWAY_JSON_FORMAT,
    GATEWAY_BINARY_FORMAT,
} gateway_out_format_t;

typedef struct
{
    bool enabled;
    char path[48];
    uint16_t interval;
    gateway_out_format_t format;
} gateway_out_config_t;

typedef struct
{
    uint32_t id;
    gateway_out_config_t data_out;
    gateway_out_config_t health_out;
} gateway_config_t;

/**
 * @brief Serialize an gateway_out_config_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t gateway_out_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(gateway_out_config_t));

/**
 * @brief Deserialize an gateway_out_config_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t gateway_out_config_to_json(PRODAQ_TO_JSON_PARAMETERS(gateway_out_config_t));

/**
 * @brief Serialize an gateway_config_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t gateway_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(gateway_config_t));

/**
 * @brief Deserialize an gateway_config_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t gateway_config_to_json(PRODAQ_TO_JSON_PARAMETERS(gateway_config_t));

#ifdef __cplusplus
}
#endif

#endif  //!__GATEWAY_CONFIG__H__