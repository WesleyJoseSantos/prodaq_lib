/**
 * @file protocol_mqtt.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __PROTOCOL_MQTT__H__
#define __PROTOCOL_MQTT__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <inttypes.h>
#include "prodaq_json.h"

/**
 * @brief MQTT configuration
 *
 */
typedef struct protocol_mqtt_config
{
    char host[128];    // MQTT hostname
    int port;          // MQTT port
    char username[64]; // MQTT username
    char password[64]; // MQTT password
    uint8_t transport; // MQTT transport
    uint8_t qos;       // MQTT lowest qos
    char rx_topic[48]; // MQTT topic used to receive data
    char tx_topic[48]; // MQTT topic used to send data
} mqtt_config_t;

/**
 * @brief Serialize an mqtt_config_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t mqtt_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(mqtt_config_t));

/**
 * @brief Deserialize an mqtt_config_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t mqtt_config_to_json(PRODAQ_TO_JSON_PARAMETERS(mqtt_config_t));

#ifdef __cplusplus
}
#endif

#endif //!__PROTOCOL_MQTT__H__