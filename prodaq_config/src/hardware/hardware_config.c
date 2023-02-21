/**
 * @file hardware_config.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "hardware/hardware_config.h"
#include "hardware/hardware_message.h"

prodaq_err_t hardware_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(hardware_config_t), hardware_interface_t type)
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    switch (type)
    {
    case HW_INTERFACE_WIFI:      
        return wifi_config_from_json(json, &ptr->wifi);
    case HW_INTERFACE_ETHERNET:
        return ethernet_config_from_json(json, &ptr->ethernet);
    case HW_INTERFACE_UART:
        return uart_config_from_json(json, &ptr->uart);
    default:
        return PRODAQ_ERR_INVALID_TYPE;
    }
    return PRODAQ_OK;
}

prodaq_err_t hardware_config_to_json(PRODAQ_TO_JSON_PARAMETERS(hardware_config_t), hardware_interface_t type)
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    switch (type)
    {
    case HW_INTERFACE_WIFI:      
        return wifi_config_to_json(&ptr->wifi, json);
    case HW_INTERFACE_ETHERNET:
        return ethernet_config_to_json(&ptr->ethernet, json);
    case HW_INTERFACE_UART:
        return uart_config_to_json(&ptr->uart, json);
    default:
        return PRODAQ_ERR_INVALID_TYPE;
    }
    return PRODAQ_OK;
}
