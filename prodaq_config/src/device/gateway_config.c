/**
 * @file gateway_config.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "device/gateway_config.h"

prodaq_err_t gateway_out_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(gateway_out_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_BOOLEAN(enabled);
    PRODAQ_FROM_JSON_CHAR_ARRAY(path);
    PRODAQ_FROM_JSON_NUMBER(interval);
    PRODAQ_FROM_JSON_NUMBER(format);
    return PRODAQ_OK;
}

prodaq_err_t gateway_out_config_to_json(PRODAQ_TO_JSON_PARAMETERS(gateway_out_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_BOOLEAN(enabled);
    PRODAQ_TO_JSON_CHAR_ARRAY(path);
    PRODAQ_TO_JSON_NUMBER(interval);
    PRODAQ_TO_JSON_NUMBER(format);
    return PRODAQ_OK;
}

prodaq_err_t gateway_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(gateway_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER(id);
    PRODAQ_FROM_JSON_OBJ(data_out, gateway_out_config_from_json);
    PRODAQ_FROM_JSON_OBJ(health_out, gateway_out_config_from_json);
    return PRODAQ_OK;
}

prodaq_err_t gateway_config_to_json(PRODAQ_TO_JSON_PARAMETERS(gateway_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER(id);
    PRODAQ_TO_JSON_OBJ(data_out, gateway_out_config_to_json);
    PRODAQ_TO_JSON_OBJ(health_out, gateway_out_config_to_json);
    return PRODAQ_OK;
}
