/**
 * 3@file info_message.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __INFO_MESSAGE__H__
#define __INFO_MESSAGE__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "info_data.h"

typedef struct
{
    info_type_t type;
    info_data_t info;
} info_message_t;

/**
 * @brief Serialize an info_message_t object to cJSON object
 *
 * @return prodaq_err_t err code
 */
prodaq_err_t info_message_from_json(PRODAQ_FROM_JSON_PARAMETERS(info_message_t));

/**
 * @brief Deserialize an info_message_t object using an cJSON object
 *
 * @param interface Hardware interface that will be serialized to cJSON pbject
 * @return prodaq_err_t err code
 */
prodaq_err_t info_message_to_json(PRODAQ_TO_JSON_PARAMETERS(info_message_t));

#ifdef __cplusplus
}
#endif

#endif  //!__INFO_MESSAGE__H__