/**
 * @file hardware_ip.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ip_config.h"

prodaq_err_t ip_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(ip_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_BOOLEAN(enabled);
    PRODAQ_FROM_JSON_NUMBER_ARRAY(address);
    PRODAQ_FROM_JSON_NUMBER_ARRAY(mask);
    PRODAQ_FROM_JSON_NUMBER_ARRAY(gateway);
    PRODAQ_FROM_JSON_NUMBER_ARRAY(dns);
    return PRODAQ_OK;
}

prodaq_err_t ip_config_to_json(PRODAQ_TO_JSON_PARAMETERS(ip_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_BOOLEAN(enabled);
    PRODAQ_TO_JSON_NUMBER_ARRAY(address);
    PRODAQ_TO_JSON_NUMBER_ARRAY(mask);
    PRODAQ_TO_JSON_NUMBER_ARRAY(gateway);
    PRODAQ_TO_JSON_NUMBER_ARRAY(dns);
    return PRODAQ_OK;
}
