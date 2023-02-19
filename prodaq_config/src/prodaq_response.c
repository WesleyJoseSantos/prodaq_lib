/**
 * @file response_message.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "prodaq_response.h"

prodaq_err_t response_message_from_json(PRODAQ_FROM_JSON_PARAMETERS(response_message_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER(err);
    PRODAQ_FROM_JSON_CHAR_ARRAY(message);
    return PRODAQ_OK;
}

prodaq_err_t response_message_to_json(PRODAQ_TO_JSON_PARAMETERS(response_message_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER(err);
    PRODAQ_TO_JSON_CHAR_ARRAY(message);
    return PRODAQ_OK;
}
