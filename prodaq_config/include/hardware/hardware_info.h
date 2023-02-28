/**
 * @file hardware_info.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __HARDWARE_INFO__H__
#define __HARDWARE_INFO__H__

#include <inttypes.h>
#include "prodaq_json.h"

typedef enum
{
    HARDWARE_TYPE_UNKNOWN,
    HARDWARE_TYPE_SENSOR,
    HARDWARE_TYPE_GATEWAY,
    HARDWARE_TYPE_DATALOGGER,
} hardware_type_t;

typedef enum
{
    HARDWARE_FEATURE_WIFI,
    HARDWARE_FEATURE_BLE,
    HARDWARE_FEATURE_ZIGBEE,
    HARDWARE_FEATURE_LORA,
    HARDWARE_FEATURE_ETHERNET,
    HARDWREA_FEATURE_RS232,
    HARDWARE_FEATURE_RS485,
    HARDWARE_FEATURE_CAN,
    HARDWARE_FEATURE_STORAGE,
    HARDWARE_FEATURE_HMI,
} hardware_features_t;

typedef struct
{
    hardware_type_t type;
    char board[16];
    char version[16];
    char mcu[16];
    uint8_t mac_wifi[6];
    uint8_t mac_ble[6];
    uint8_t mac_eth[6];
    uint8_t mac_zigbee[8];
    uint8_t mac_lora[8];
    uint32_t storage_bytes;
    hardware_features_t features; 
} hardware_info_t;

/**
 * @brief Serialize an hardware_info_t object to cJSON object
 *
 * @return prodaq_err_t err code
 */
prodaq_err_t hardware_info_from_json(PRODAQ_FROM_JSON_PARAMETERS(hardware_info_t));

/**
 * @brief Deserialize an hardware_info_t object using an cJSON object
 *
 * @param type Protocol config that will be serialized to cJSON object
 * @return prodaq_err_t err code
 */
prodaq_err_t hardware_info_to_json(PRODAQ_TO_JSON_PARAMETERS(hardware_info_t));

#endif  //!__HARDWARE_INFO__H__