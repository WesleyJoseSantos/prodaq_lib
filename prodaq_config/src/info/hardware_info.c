/**
 * @file hardware_info.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "info/hardware_info.h"

prodaq_err_t hardware_info_from_json(PRODAQ_FROM_JSON_PARAMETERS(hardware_info_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER(type);
    PRODAQ_FROM_JSON_CHAR_ARRAY(board);
    PRODAQ_FROM_JSON_CHAR_ARRAY(version);
    PRODAQ_FROM_JSON_CHAR_ARRAY(mcu);
    PRODAQ_FROM_JSON_NUMBER_ARRAY(mac_wifi);
    PRODAQ_FROM_JSON_NUMBER_ARRAY(mac_ble);
    PRODAQ_FROM_JSON_NUMBER_ARRAY(mac_eth);
    PRODAQ_FROM_JSON_NUMBER_ARRAY(mac_zigbee);
    PRODAQ_FROM_JSON_NUMBER_ARRAY(mac_lora);
    PRODAQ_FROM_JSON_NUMBER(storage_bytes);
    PRODAQ_FROM_JSON_NUMBER(features);
    return PRODAQ_OK;
}

prodaq_err_t hardware_info_to_json(PRODAQ_TO_JSON_PARAMETERS(hardware_info_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER(type);
    PRODAQ_TO_JSON_CHAR_ARRAY(board);
    PRODAQ_TO_JSON_CHAR_ARRAY(version);
    PRODAQ_TO_JSON_CHAR_ARRAY(mcu);
    PRODAQ_TO_JSON_NUMBER_ARRAY(mac_wifi);
    PRODAQ_TO_JSON_NUMBER_ARRAY(mac_ble);
    PRODAQ_TO_JSON_NUMBER_ARRAY(mac_eth);
    PRODAQ_TO_JSON_NUMBER_ARRAY(mac_zigbee);
    PRODAQ_TO_JSON_NUMBER_ARRAY(mac_lora);
    PRODAQ_TO_JSON_NUMBER(storage_bytes);
    PRODAQ_TO_JSON_NUMBER(features);
    return PRODAQ_OK;
}
