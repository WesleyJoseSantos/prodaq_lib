/**
 * @file protocol_message.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __PROTOCOL_MESSAGE__H__
#define __PROTOCOL_MESSAGE__H__

#include <stdbool.h>
#include "protocol_config.h"
#include "prodaq_json.h"

/**
 * @brief Protocol config message
 *
 */
typedef struct
{
    protocol_t type;          // Number that indicates which type this configuration belongs to
    bool enabled;             // Flag that signs if interface is enabled or disabled
    protocol_config_t config; // Protocol configuration
} protocol_message_t;

/**
 * @brief Serialize an protocol_message_t object to cJSON object
 *
 * @return prodaq_err_t err code
 */
prodaq_err_t protocol_message_from_json(PRODAQ_FROM_JSON_PARAMETERS(protocol_message_t));

/**
 * @brief Deserialize an protocol_message_t object using an cJSON object
 *
 * @param type
 * @return prodaq_err_t err code
 */
prodaq_err_t protocol_message_to_json(PRODAQ_TO_JSON_PARAMETERS(protocol_message_t));

#endif //!__PROTOCOL_MESSAGE__H__