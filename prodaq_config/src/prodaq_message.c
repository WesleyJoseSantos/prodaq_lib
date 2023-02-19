/**
 * @file prodaq_message.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "prodaq_message.h"

prodaq_err_t message_from_json(PRODAQ_FROM_JSON_PARAMETERS(message_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER(id);
    PRODAQ_FROM_JSON_UNION(data, message_data_from_json, ptr->id);
    return PRODAQ_OK;
}

prodaq_err_t message_to_json(PRODAQ_TO_JSON_PARAMETERS(message_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER(id);
    PRODAQ_TO_JSON_UNION(data, message_data_to_json, ptr->id);
    return PRODAQ_OK;
}
