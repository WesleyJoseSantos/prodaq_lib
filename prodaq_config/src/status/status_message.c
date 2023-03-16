/**
 * @file status_message.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "status/status_message.h"

prodaq_err_t status_message_from_json(PRODAQ_FROM_JSON_PARAMETERS(status_message_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER(type);
    PRODAQ_FROM_JSON_UNION(status, status_data_from_json, ptr->type);
    return PRODAQ_OK;
}

prodaq_err_t status_message_to_json(PRODAQ_TO_JSON_PARAMETERS(status_message_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER(type);
    PRODAQ_TO_JSON_UNION(status, status_data_to_json, ptr->type);
    return PRODAQ_OK;
}
