/**
 * @file hardware_config.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __HARDWARE_CONFIG__H__
#define __HARDWARE_CONFIG__H__

#include "wifi_config.h"
#include "ethernet_config.h"
#include "uart_config.h"
#include "prodaq_json.h"

/**
 * @brief Interface types
 *
 */
typedef enum
{
    HW_INTERFACE_WIFI = 1, // Interface wifi
    HW_INTERFACE_ETHERNET, // Interface ethernet
    HW_INTERFACE_UART      // Interface uart
} hardware_interface_t;

/**
 * @brief Hardware config union
 *
 */
typedef union
{
    wifi_config_t wifi;         // Wifi configuration
    ethernet_config_t ethernet; // Ethernet configuration
    uart_config_t uart;         // Uart configuration
} hardware_config_t;

/**
 * @brief Serialize an hardware_config_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t hardware_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(hardware_config_t), hardware_interface_t type);

/**
 * @brief Deserialize an hardware_config_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t hardware_config_to_json(PRODAQ_TO_JSON_PARAMETERS(hardware_config_t), hardware_interface_t type);

#endif //!__HARDWARE_CONFIG__H__