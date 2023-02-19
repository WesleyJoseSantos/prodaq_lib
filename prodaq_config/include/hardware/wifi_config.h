/**
 * @file hardware_wifi.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __HARDWARE_WIFI__H__
#define __HARDWARE_WIFI__H__

#include "ip_config.h"
#include "prodaq_json.h"

/**
 * @brief Wifi configuration
 *
 */
typedef struct
{
    char ssid[32];           // Wifi ssid
    char password[32];       // Wifi password
    ip_config_t ip; // Wifi IP conifguration
    char identity[127];      // Wifi enterprise identity
    char username[127];      // Wifi enterprise username
} wifi_config_t;

/**
 * @brief Serialize an wifi_config_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t wifi_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(wifi_config_t));

/**
 * @brief Deserialize an wifi_config_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t wifi_config_to_json(PRODAQ_TO_JSON_PARAMETERS(wifi_config_t));

#endif //!__HARDWARE_WIFI__H__