/**
 * 3@file info_data.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "info/info_data.h"
#include "info/hardware_info.h"

prodaq_err_t info_data_from_json(PRODAQ_FROM_JSON_PARAMETERS(info_data_t), info_type_t type)
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    switch (type)
    {
    case INFO_HARDWARE:      
        return hardware_info_from_json(json, &ptr->hardware);
    default:
        return PRODAQ_ERR_INVALID_TYPE;
    }
    return PRODAQ_OK;
}

prodaq_err_t info_data_to_json(PRODAQ_TO_JSON_PARAMETERS(info_data_t), info_type_t type)
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    switch (type)
    {
    case INFO_HARDWARE:      
        return hardware_info_to_json(&ptr->hardware, json);
    default:
        return PRODAQ_ERR_INVALID_TYPE;
    }
    return PRODAQ_OK;
}
