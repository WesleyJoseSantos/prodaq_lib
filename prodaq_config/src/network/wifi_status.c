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

#include "network/wifi_status.h"

prodaq_err_t wifi_status_from_json(PRODAQ_FROM_JSON_PARAMETERS(wifi_status_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_OBJ(tcp, tcp_status_from_json);
    PRODAQ_FROM_JSON_CHAR_ARRAY(ssid);
    PRODAQ_FROM_JSON_NUMBER(rssi);
    return PRODAQ_OK;
}

prodaq_err_t wifi_status_to_json(PRODAQ_TO_JSON_PARAMETERS(wifi_status_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_OBJ(tcp, tcp_status_to_json);
    PRODAQ_TO_JSON_CHAR_ARRAY(ssid);
    PRODAQ_TO_JSON_NUMBER(rssi);
    return PRODAQ_OK;
}
