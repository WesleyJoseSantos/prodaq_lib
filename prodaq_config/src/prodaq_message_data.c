/**
 * @file message_data.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "prodaq_message_data.h"

prodaq_err_t message_data_from_json(PRODAQ_FROM_JSON_PARAMETERS(message_data_t), message_id_t type)
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    switch (type)
    {
    case MSG_ID_HARDWARE_CONFIG:
        return hardware_message_from_json(json, &ptr->hardware);
    case MSG_ID_PROTOCOL_CONFIG:
        return protocol_message_from_json(json, &ptr->protocol);
    case MSG_ID_DEVICE_CONFIG:
        return device_message_from_json(json, &ptr->device);
    case MSG_ID_REQUEST:
        return request_message_from_json(json, &ptr->request);
    case MSG_ID_RESPONSE:
        return response_message_from_json(json, &ptr->response);
    default:
        return PRODAQ_ERR_INVALID_TYPE;
    }
    return PRODAQ_OK;
}

prodaq_err_t message_data_to_json(PRODAQ_TO_JSON_PARAMETERS(message_data_t), message_id_t type)
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    switch (type)
    {
    case MSG_ID_HARDWARE_CONFIG:
        hardware_message_to_json(&ptr->hardware, json);
        break;
    case MSG_ID_PROTOCOL_CONFIG:
        protocol_message_to_json(&ptr->protocol, json);
        break;
    case MSG_ID_DEVICE_CONFIG:
        device_message_to_json(&ptr->device, json);
        break;
    case MSG_ID_REQUEST:
        request_message_to_json(&ptr->request, json);
        break;
    case MSG_ID_RESPONSE:
        response_message_to_json(&ptr->response, json);
        break;
    default:
        return PRODAQ_ERR_INVALID_TYPE;
    }
    return PRODAQ_OK;
}
