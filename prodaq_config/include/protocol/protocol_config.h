/**
 * @file protocol_config.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __PROTOCOL_CONFIG__H__
#define __PROTOCOL_CONFIG__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "ntp_config.h"
#include "http_config.h"
#include "mqtt_config.h"
#include "prodaq_json.h"

/**
 * @brief Protocol types
 *
 */
typedef enum
{
    PROTOCOL_NTP = 1, // NTP type
    PROTOCOL_HTTP,    // HTTP type
    PROTOCOL_MQTT,    // MQTT type
    // PROTOCOL_OPCUA,  // OPCUA type
    // PROTOCOL_MODBUS, // Modbus type
} protocol_t;

/**
 * @brief Protocol config union
 *
 */
typedef union
{
    ntp_config_t ntp;   // NTP configuration
    http_config_t http; // HTTP configuration
    mqtt_config_t mqtt; // MQTT configuration
} protocol_config_t;

/**
 * @brief Serialize an protocol_config_t object to cJSON object
 *
 * @return prodaq_err_t err code
 */
prodaq_err_t protocol_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(protocol_config_t), protocol_t type);

/**
 * @brief Deserialize an protocol_config_t object using an cJSON object
 *
 * @param type Protocol config that will be serialized to cJSON object
 * @return prodaq_err_t err code
 */
prodaq_err_t protocol_config_to_json(PRODAQ_TO_JSON_PARAMETERS(protocol_config_t), protocol_t type);

#ifdef __cplusplus
}
#endif

#endif //!__PROTOCOL_CONFIG__H__