/**
 * @file status_message.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __STATUS_MESSAGE__H__
#define __STATUS_MESSAGE__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "status_data.h"

typedef struct
{
    status_type_t type;
    status_data_t status;
} status_message_t;

/**
 * @brief Serialize an status_message_t object to cJSON object
 *
 * @return prodaq_err_t err code
 */
prodaq_err_t status_message_from_json(PRODAQ_FROM_JSON_PARAMETERS(status_message_t));

/**
 * @brief Deserialize an status_message_t object using an cJSON object
 *
 * @param type
 * @return prodaq_err_t err code
 */
prodaq_err_t status_message_to_json(PRODAQ_TO_JSON_PARAMETERS(status_message_t));

#ifdef __cplusplus
}
#endif

#endif  //!__STATUS_MESSAGE__H__