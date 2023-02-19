/**
 * @file sensor_config.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "sensor_config.h"

prodaq_err_t sensor_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(sensor_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER(id);
    PRODAQ_FROM_JSON_NUMBER(interval);
    PRODAQ_FROM_JSON_NUMBER(resolution);
    PRODAQ_FROM_JSON_NUMBER(samples);
    PRODAQ_FROM_JSON_NUMBER(data_type);
    PRODAQ_FROM_JSON_NUMBER(hardware);
    return PRODAQ_OK;
}

prodaq_err_t sensor_config_to_json(PRODAQ_TO_JSON_PARAMETERS(sensor_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER(id);
    PRODAQ_TO_JSON_NUMBER(interval);
    PRODAQ_TO_JSON_NUMBER(resolution);
    PRODAQ_TO_JSON_NUMBER(samples);
    PRODAQ_TO_JSON_NUMBER(data_type);
    PRODAQ_TO_JSON_NUMBER(hardware);
    return PRODAQ_OK;
}
