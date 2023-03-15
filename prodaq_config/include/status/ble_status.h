/**
 * @file ble_status.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __BLE_STATUS__H__
#define __BLE_STATUS__H__

#include <inttypes.h>
#include <stdbool.h>
#include "prodaq_json.h"

typedef struct
{
    int8_t rssi;
    bool connected;
} ble_status_t;

/**
 * @brief Serialize an ble_status_t object to cJSON object
 *
 * @return prodaq_err_t err code
 */
prodaq_err_t ble_status_from_json(PRODAQ_FROM_JSON_PARAMETERS(ble_status_t));

/**
 * @brief Deserialize an ble_status_t object using an cJSON object
 *
 * @param type Protocol config that will be serialized to cJSON object
 * @return prodaq_err_t err code
 */
prodaq_err_t ble_status_to_json(PRODAQ_TO_JSON_PARAMETERS(ble_status_t));

#endif  //!__BLE_STATUS__H__