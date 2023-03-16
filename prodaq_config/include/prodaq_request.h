/**
 * @file prodaq_request.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __PRODAQ_REQUEST__H__
#define __PRODAQ_REQUEST__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <inttypes.h>

#include "prodaq_err.h"
#include "prodaq_json.h"

/**
 * @brief Request message
 * 
 */
typedef struct
{
    uint16_t id;       // Id of requested resource
    uint16_t type;     // Type of requested resource;
} request_message_t;

/**
 * @brief Serialize an request_message_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t request_message_from_json(PRODAQ_FROM_JSON_PARAMETERS(request_message_t));

/**
 * @brief Deserialize an request_message_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t request_message_to_json(PRODAQ_TO_JSON_PARAMETERS(request_message_t));

#ifdef __cplusplus
}
#endif

#endif //!__PRODAQ_REQUEST__H__