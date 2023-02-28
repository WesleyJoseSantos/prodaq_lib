/**
 * @file network_status.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __NETWORK_STATUS__H__
#define __NETWORK_STATUS__H__

#include <inttypes.h>
#include "tcp_status.h"
#include "wifi_status.h"
#include "ble_status.h"
#include "prodaq_json.h"

typedef struct
{
    tcp_status_t ethernet;
    wifi_status_t wifi;
    ble_status_t ble;
    bool mqtt;
    bool ntp;
} network_status_t;

/**
 * @brief Serialize an network_status_t object to cJSON object
 *
 * @return prodaq_err_t err code
 */
prodaq_err_t network_status_from_json(PRODAQ_FROM_JSON_PARAMETERS(network_status_t));

/**
 * @brief Deserialize an network_status_t object using an cJSON object
 *
 * @param type Protocol config that will be serialized to cJSON object
 * @return prodaq_err_t err code
 */
prodaq_err_t network_status_to_json(PRODAQ_TO_JSON_PARAMETERS(network_status_t));

#endif  //!__NETWORK_STATUS__H__