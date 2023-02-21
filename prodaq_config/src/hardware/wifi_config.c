/**
 * @file hardware_wifi.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "hardware/wifi_config.h"

prodaq_err_t wifi_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(wifi_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_CHAR_ARRAY(ssid);
    PRODAQ_FROM_JSON_CHAR_ARRAY(password);
    PRODAQ_FROM_JSON_CHAR_ARRAY(identity);
    PRODAQ_FROM_JSON_CHAR_ARRAY(username);
    PRODAQ_FROM_JSON_OBJ(ip, ip_config_from_json);
    return PRODAQ_OK;
}

prodaq_err_t wifi_config_to_json(PRODAQ_TO_JSON_PARAMETERS(wifi_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_CHAR_ARRAY(ssid);
    PRODAQ_TO_JSON_CHAR_ARRAY(password);
    PRODAQ_TO_JSON_BOOLEAN(enterprise);
    PRODAQ_TO_JSON_CHAR_ARRAY(identity);
    PRODAQ_TO_JSON_CHAR_ARRAY(username);
    PRODAQ_TO_JSON_OBJ(ip, ip_config_to_json);
    return PRODAQ_OK;
}
