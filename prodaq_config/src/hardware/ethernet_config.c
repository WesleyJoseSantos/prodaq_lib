/**
 * @file hardware_ethernet.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "hardware/ethernet_config.h"

prodaq_err_t ethernet_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(ethernet_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_OBJ(ip, ip_config_from_json);
    return PRODAQ_OK;
}

prodaq_err_t ethernet_config_to_json(PRODAQ_TO_JSON_PARAMETERS(ethernet_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_OBJ(ip, ip_config_to_json);
    return PRODAQ_OK;
}
