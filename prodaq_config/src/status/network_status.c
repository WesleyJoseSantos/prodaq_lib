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

#include "network/network_status.h"

prodaq_err_t network_status_from_json(PRODAQ_FROM_JSON_PARAMETERS(network_status_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_OBJ(ethernet, tcp_status_from_json);
    PRODAQ_FROM_JSON_OBJ(wifi, wifi_status_from_json);
    PRODAQ_FROM_JSON_OBJ(ble, ble_status_from_json);
    PRODAQ_FROM_JSON_BOOLEAN(mqtt);
    PRODAQ_FROM_JSON_BOOLEAN(ntp);
    return PRODAQ_OK;
}

prodaq_err_t network_status_to_json(PRODAQ_TO_JSON_PARAMETERS(network_status_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_OBJ(ethernet, tcp_status_to_json);
    PRODAQ_TO_JSON_OBJ(wifi, wifi_status_to_json);
    PRODAQ_TO_JSON_OBJ(ble, ble_status_to_json);
    PRODAQ_TO_JSON_BOOLEAN(mqtt);
    PRODAQ_TO_JSON_BOOLEAN(ntp);
    return PRODAQ_OK;
}
