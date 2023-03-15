/**
 * @file tcp_status.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "status/tcp_status.h"

prodaq_err_t tcp_status_from_json(PRODAQ_FROM_JSON_PARAMETERS(tcp_status_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER_ARRAY(ip);
    PRODAQ_FROM_JSON_BOOLEAN(connected);
    return PRODAQ_OK;
}

prodaq_err_t tcp_status_to_json(PRODAQ_TO_JSON_PARAMETERS(tcp_status_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER_ARRAY(ip);
    PRODAQ_TO_JSON_BOOLEAN(connected);
    return PRODAQ_OK;
}
