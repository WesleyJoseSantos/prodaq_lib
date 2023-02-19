/**
 * @file hardware_message.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __HARDWARE_MESSAGE__H__
#define __HARDWARE_MESSAGE__H__

#include "hardware_config.h"
#include <stdbool.h>
#include "prodaq_json.h"

/**
 * @brief Hardware config message
 *
 */
typedef struct
{
    hardware_interface_t type; // Number that indicates which interface this configuration belongs to
    bool enabled;              // Flag that signs if interface is enabled or disabled
    hardware_config_t config;  // Interface hardware configuration
} hardware_message_t;

/**
 * @brief Serialize an hardware_message_t object to cJSON object
 *
 * @return prodaq_err_t err code
 */
prodaq_err_t hardware_message_from_json(PRODAQ_FROM_JSON_PARAMETERS(hardware_message_t));

/**
 * @brief Deserialize an hardware_message_t object using an cJSON object
 *
 * @param interface Hardware interface that will be serialized to cJSON pbject
 * @return prodaq_err_t err code
 */
prodaq_err_t hardware_message_to_json(PRODAQ_TO_JSON_PARAMETERS(hardware_message_t));

#endif //!__HARDWARE_MESSAGE__H__