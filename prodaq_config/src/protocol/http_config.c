/**
 * @file protocol_http.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "protocol/http_config.h"

prodaq_err_t http_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(http_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER(port);
    PRODAQ_FROM_JSON_CHAR_ARRAY(url);
    PRODAQ_FROM_JSON_CHAR_ARRAY(cert_file);
    PRODAQ_FROM_JSON_NUMBER(transport_type);
    PRODAQ_FROM_JSON_OBJ(auth, http_auth_config_from_json);
    return PRODAQ_OK;
}

prodaq_err_t http_config_to_json(PRODAQ_TO_JSON_PARAMETERS(http_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER(port);
    PRODAQ_TO_JSON_CHAR_ARRAY(url);
    PRODAQ_TO_JSON_CHAR_ARRAY(cert_file);
    PRODAQ_TO_JSON_NUMBER(transport_type);
    PRODAQ_TO_JSON_OBJ(auth, http_auth_config_to_json);
    return PRODAQ_OK;
}
