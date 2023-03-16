/**
 * @file status_data.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __STATUS_DATA__H__
#define __STATUS_DATA__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "tcp_status.h"
#include "wifi_status.h"
#include "ble_status.h"
#include "network_status.h"

typedef enum
{
    STATUS_ETHERNET,
    STATUS_WIFI,
    STATUS_BLE,
    STATUS_NETWORK,
} status_type_t;

typedef union
{
    tcp_status_t ethernet;
    wifi_status_t wifi;
    ble_status_t ble;
    network_status_t network;
} status_data_t;

/**
 * @brief Serialize an status_data_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t status_data_from_json(PRODAQ_FROM_JSON_PARAMETERS(status_data_t), status_type_t type);

/**
 * @brief Deserialize an status_data_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t status_data_to_json(PRODAQ_TO_JSON_PARAMETERS(status_data_t), status_type_t type);

#ifdef __cplusplus
}
#endif

#endif  //!__STATUS_DATA__H__