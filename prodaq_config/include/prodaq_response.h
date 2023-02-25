/**
 * @file prodaq_response.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __PRODAQ_RESPONSE__H__
#define __PRODAQ_RESPONSE__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "prodaq_json.h"

/**
 * @brief Response message
 * 
 */
typedef struct
{
    prodaq_err_t err;   // Err code of response message
    char message[256];  // Response message text
} response_message_t;

/**
 * @brief Serialize an response_message_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t response_message_from_json(PRODAQ_FROM_JSON_PARAMETERS(response_message_t));

/**
 * @brief Deserialize an response_message_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t response_message_to_json(PRODAQ_TO_JSON_PARAMETERS(response_message_t));

#ifdef __cplusplus
}
#endif

#endif  //!__PRODAQ_RESPONSE__H__