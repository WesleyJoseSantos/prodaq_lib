/**
 * @file ble_status.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "network/ble_status.h"

prodaq_err_t ble_status_from_json(PRODAQ_FROM_JSON_PARAMETERS(ble_status_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER(rssi);
    PRODAQ_FROM_JSON_BOOLEAN(connected);
    return PRODAQ_OK;
}

prodaq_err_t ble_status_to_json(PRODAQ_TO_JSON_PARAMETERS(ble_status_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER(rssi);
    PRODAQ_TO_JSON_BOOLEAN(connected);
    return PRODAQ_OK;
}
