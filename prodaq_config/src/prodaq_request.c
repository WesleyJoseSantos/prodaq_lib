/**
 * @file prodaq_request.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "prodaq_request.h"

prodaq_err_t request_message_from_json(PRODAQ_FROM_JSON_PARAMETERS(request_message_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER(id);
    PRODAQ_FROM_JSON_NUMBER(type);
    return PRODAQ_OK;
}

prodaq_err_t request_message_to_json(PRODAQ_TO_JSON_PARAMETERS(request_message_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER(id);
    PRODAQ_TO_JSON_NUMBER(type);
    return PRODAQ_OK;
}
