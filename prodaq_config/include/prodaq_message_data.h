/**
 * @file message_data.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __PRODAQ_MESSAGE_DATA__H__
#define __PRODAQ_MESSAGE_DATA__H__

#include "hardware/hardware_message.h"
#include "protocol/protocol_message.h"
#include "device/device_message.h"
#include "prodaq_request.h"
#include "prodaq_response.h"
#include "prodaq_json.h"

/**
 * @brief Message types
 *
 */
typedef enum
{
    MSG_ID_INVALID = 0,         // Invalid message id
    MSG_ID_HARDWARE_CONFIG = 1, // Message id for hardware configuration
    MSG_ID_PROTOCOL_CONFIG = 2, // Message id for protocol configuration
    MSG_ID_DEVICE_CONFIG = 3,   // Message id for device configuration
    MSG_ID_REQUEST = 127,       // Message id to request an resource
    MSG_ID_RESPONSE = 255,      // Message id that responds an configuration message
} message_id_t;

/**
 * @brief Union of message data
 *
 */
typedef union
{
    hardware_message_t hardware; // Hardware configuration data
    protocol_message_t protocol; // Protocol configuration data
    device_message_t device;     // Device configuration data
    request_message_t request;   // Message to request an resource
    response_message_t response; // Message that responds an configuration message
} message_data_t;

/**
 * @brief Serialize an message_data_t object to cJSON object
 *
 * @return prodaq_err_t err code
 */
prodaq_err_t message_data_from_json(PRODAQ_FROM_JSON_PARAMETERS(message_data_t), message_id_t id);

/**
 * @brief Deserialize an message_data_t object using an cJSON object
 *
 * @param id
 * @return prodaq_err_t err code
 */
prodaq_err_t message_data_to_json(PRODAQ_TO_JSON_PARAMETERS(message_data_t), message_id_t id);

#endif //!__PRODAQ_MESSAGE_DATA__H__