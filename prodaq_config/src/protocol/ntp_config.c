/**
 * @file protocol_ntp.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "protocol/ntp_config.h"

prodaq_err_t ntp_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(ntp_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER(op_mode);
    PRODAQ_FROM_JSON_NUMBER(sync_interval);
    PRODAQ_FROM_JSON_NUMBER(sync_mode);
    PRODAQ_FROM_JSON_CHAR_ARRAY(server1);
    PRODAQ_FROM_JSON_CHAR_ARRAY(server2);
    PRODAQ_FROM_JSON_CHAR_ARRAY(server3);
    return PRODAQ_OK;
}

prodaq_err_t ntp_config_to_json(PRODAQ_TO_JSON_PARAMETERS(ntp_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER(op_mode);
    PRODAQ_TO_JSON_NUMBER(sync_interval);
    PRODAQ_TO_JSON_NUMBER(sync_mode);
    PRODAQ_TO_JSON_CHAR_ARRAY(server1);
    PRODAQ_TO_JSON_CHAR_ARRAY(server2);
    PRODAQ_TO_JSON_CHAR_ARRAY(server3);
    return PRODAQ_OK;
}
