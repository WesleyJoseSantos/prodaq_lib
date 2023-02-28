/**
 * @file device_config.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "device/device_config.h"

prodaq_err_t device_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(device_config_t), device_t type)
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    switch (type)
    {
    case DEVICE_SENSOR:
        return sensor_config_from_json(json, &ptr->sensor);
    case DEVICE_GATEWAY:
        return gateway_config_from_json(json, &ptr->gateway);
    case DEVICE_DATALOGGER:
        return datalogger_config_from_json(json, &ptr->datalogger);
    default:
        return PRODAQ_ERR_INVALID_TYPE;
    }
    return PRODAQ_OK;
}

prodaq_err_t device_config_to_json(PRODAQ_TO_JSON_PARAMETERS(device_config_t), device_t type)
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    switch (type)
    {
    case DEVICE_SENSOR:
        return sensor_config_to_json(&ptr->sensor, json);
    case DEVICE_GATEWAY:
        return gateway_config_to_json(&ptr->gateway, json);
    case DEVICE_DATALOGGER:
        return datalogger_config_to_json(&ptr->datalogger, json);
    default:
        return PRODAQ_ERR_INVALID_TYPE;
    }
    return PRODAQ_OK;
}
