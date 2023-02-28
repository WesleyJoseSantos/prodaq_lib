/**
 * @file datalogger_config.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "device/datalogger_config.h"

prodaq_err_t datalogger_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(datalogger_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER(id);
    PRODAQ_FROM_JSON_NUMBER(interval);
    PRODAQ_FROM_JSON_CHAR_ARRAY(file_path);
    PRODAQ_FROM_JSON_NUMBER(file_max_size);
    return PRODAQ_OK;
}

prodaq_err_t datalogger_config_to_json(PRODAQ_TO_JSON_PARAMETERS(datalogger_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER(id);
    PRODAQ_TO_JSON_NUMBER(interval);
    PRODAQ_TO_JSON_CHAR_ARRAY(file_path);
    PRODAQ_TO_JSON_NUMBER(file_max_size);
    return PRODAQ_OK;
}
