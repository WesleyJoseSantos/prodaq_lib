/**
 * @file prodaq_message.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __PRODAQ_MESSAGE__H__
#define __PRODAQ_MESSAGE__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "prodaq_message_data.h"
#include "prodaq_json.h"

/**
 * @brief Message
 *
 */
typedef struct
{
    message_id_t id;     // Message type
    message_data_t data; // Message data
} message_t;

/**
 * @brief Serialize an message_t object to cJSON object
 *
 * @return prodaq_err_t err code
 */
prodaq_err_t message_from_json(PRODAQ_FROM_JSON_PARAMETERS(message_t));

/**
 * @brief Deserialize an message_t object using an cJSON object
 *
 * @param type
 * @return prodaq_err_t err code
 */
prodaq_err_t message_to_json(PRODAQ_TO_JSON_PARAMETERS(message_t));

#ifdef __cplusplus
}
#endif

#endif //!__PRODAQ_MESSAGE__H__