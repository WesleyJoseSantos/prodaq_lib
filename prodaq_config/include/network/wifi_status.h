/**
 * @file wifi_status.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __WIFI_STATUS__H__
#define __WIFI_STATUS__H__

#include <inttypes.h>
#include "tcp_status.h"
#include "prodaq_json.h"

typedef struct
{
    tcp_status_t tcp;
    char ssid[32];
    int8_t rssi;
} wifi_status_t;

/**
 * @brief Serialize an wifi_status_t object to cJSON object
 *
 * @return prodaq_err_t err code
 */
prodaq_err_t wifi_status_from_json(PRODAQ_FROM_JSON_PARAMETERS(wifi_status_t));

/**
 * @brief Deserialize an wifi_status_t object using an cJSON object
 *
 * @param type Protocol config that will be serialized to cJSON object
 * @return prodaq_err_t err code
 */
prodaq_err_t wifi_status_to_json(PRODAQ_TO_JSON_PARAMETERS(wifi_status_t));

#endif  //!__WIFI_STATUS__H__