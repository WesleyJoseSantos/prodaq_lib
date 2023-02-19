/**
 * @file protocol_http_auth.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "http_auth_config.h"

prodaq_err_t http_auth_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(http_auth_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER(auth_type);
    PRODAQ_FROM_JSON_CHAR_ARRAY(username);
    PRODAQ_FROM_JSON_CHAR_ARRAY(password);
    PRODAQ_FROM_JSON_STRING(token);
    return PRODAQ_OK;
}

prodaq_err_t http_auth_config_to_json(PRODAQ_TO_JSON_PARAMETERS(http_auth_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER(auth_type);
    PRODAQ_TO_JSON_CHAR_ARRAY(username);
    PRODAQ_TO_JSON_CHAR_ARRAY(password);
    PRODAQ_TO_JSON_CHAR_ARRAY(token);
    return PRODAQ_OK;
}
