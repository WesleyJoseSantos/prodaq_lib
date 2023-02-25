/**
 * @file protocol_mqtt.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "protocol/mqtt_config.h"

prodaq_err_t mqtt_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(mqtt_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_CHAR_ARRAY(host);
    PRODAQ_FROM_JSON_NUMBER(port);
    PRODAQ_FROM_JSON_CHAR_ARRAY(username);
    PRODAQ_FROM_JSON_CHAR_ARRAY(password);
    PRODAQ_FROM_JSON_NUMBER(transport);
    PRODAQ_FROM_JSON_NUMBER(qos);
    PRODAQ_FROM_JSON_CHAR_ARRAY(rx_topic);
    PRODAQ_FROM_JSON_CHAR_ARRAY(tx_topic);
    return PRODAQ_OK;
}

prodaq_err_t mqtt_config_to_json(PRODAQ_TO_JSON_PARAMETERS(mqtt_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_CHAR_ARRAY(host);
    PRODAQ_TO_JSON_NUMBER(port);
    PRODAQ_TO_JSON_CHAR_ARRAY(username);
    PRODAQ_TO_JSON_CHAR_ARRAY(password);
    PRODAQ_TO_JSON_NUMBER(transport);
    PRODAQ_TO_JSON_NUMBER(qos);
    PRODAQ_TO_JSON_CHAR_ARRAY(rx_topic);
    PRODAQ_TO_JSON_CHAR_ARRAY(tx_topic);
    return PRODAQ_OK;
}
