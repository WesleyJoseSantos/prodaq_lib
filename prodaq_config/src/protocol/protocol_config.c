/**
 * @file protocol_config.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "protocol/protocol_config.h"

prodaq_err_t protocol_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(protocol_config_t), protocol_t type)
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    switch (type)
    {
    case PROTOCOL_NTP:
        return ntp_config_from_json(json, &ptr->ntp);
    case PROTOCOL_HTTP:
        return http_config_from_json(json, &ptr->http);
    case PROTOCOL_MQTT:
        return mqtt_config_from_json(json, &ptr->mqtt);
    default:
        return PRODAQ_ERR_INVALID_TYPE;
    }
    return PRODAQ_OK;
}

prodaq_err_t protocol_config_to_json(PRODAQ_TO_JSON_PARAMETERS(protocol_config_t), protocol_t type)
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    switch (type)
    {
    case PROTOCOL_NTP:
        ntp_config_to_json(&ptr->ntp, json);
        break;
    case PROTOCOL_HTTP:
        http_config_to_json(&ptr->http, json);
        break;
    case PROTOCOL_MQTT:
        mqtt_config_to_json(&ptr->mqtt, json);
        break;
    default:
        return PRODAQ_ERR_INVALID_TYPE;
    }
    return PRODAQ_OK;
}
