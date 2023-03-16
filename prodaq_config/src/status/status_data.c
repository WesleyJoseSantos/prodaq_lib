/**
 * @file status_data.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "status/status_data.h"
#include "status/tcp_status.h"
#include "status/wifi_status.h"
#include "status/ble_status.h"
#include "status/network_status.h"

prodaq_err_t status_data_from_json(PRODAQ_FROM_JSON_PARAMETERS(status_data_t), status_type_t type)
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    switch (type)
    {
    case STATUS_ETHERNET:      
        return tcp_status_from_json(json, &ptr->ethernet);
    case STATUS_WIFI:      
        return wifi_status_from_json(json, &ptr->wifi);
    case STATUS_BLE:      
        return ble_status_from_json(json, &ptr->ble);
    case STATUS_NETWORK:      
        return network_status_from_json(json, &ptr->network);
    default:
        return PRODAQ_ERR_INVALID_TYPE;
    }
    return PRODAQ_OK;
}

prodaq_err_t status_data_to_json(PRODAQ_TO_JSON_PARAMETERS(status_data_t), status_type_t type)
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    switch (type)
    {
    case STATUS_ETHERNET:      
        return tcp_status_to_json(&ptr->ethernet, json);
    case STATUS_WIFI:      
        return wifi_status_to_json(&ptr->wifi, json);
    case STATUS_BLE:      
        return ble_status_to_json(&ptr->ble, json);
    case STATUS_NETWORK:      
        return network_status_to_json(&ptr->network, json);
    default:
        return PRODAQ_ERR_INVALID_TYPE;
    }
    return PRODAQ_OK;
}
