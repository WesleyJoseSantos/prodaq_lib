/**
 * @file device_message.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __DEVICE_MESSAGE__H__
#define __DEVICE_MESSAGE__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <inttypes.h>
#include "device_config.h"
#include "prodaq_json.h"

/**
 * @brief Device config message
 *
 */
typedef struct
{
    device_t type;          // Number that indicates wich type this configuration belongs to
    bool enabled;           // Flag that signs if interface is enabled or disabled
    device_config_t config; // Device configuration
} device_message_t;

/**
 * @brief Serialize an device_message_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t device_message_from_json(PRODAQ_FROM_JSON_PARAMETERS(device_message_t));

/**
 * @brief Deserialize an device_message_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t device_message_to_json(PRODAQ_TO_JSON_PARAMETERS(device_message_t));

#ifdef __cplusplus
}
#endif

#endif //!__DEVICE_MESSAGE__H__