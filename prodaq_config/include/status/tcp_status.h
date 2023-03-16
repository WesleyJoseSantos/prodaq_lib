/**
 * @file tcp_status.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __TCP_STATUS__H__
#define __TCP_STATUS__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <inttypes.h>
#include <stdbool.h>
#include "prodaq_json.h"

typedef struct
{
    uint8_t ip[4];
    bool connected;
} tcp_status_t;

/**
 * @brief Serialize an tcp_status_t object to cJSON object
 *
 * @return prodaq_err_t err code
 */
prodaq_err_t tcp_status_from_json(PRODAQ_FROM_JSON_PARAMETERS(tcp_status_t));

/**
 * @brief Deserialize an tcp_status_t object using an cJSON object
 *
 * @param type Protocol config that will be serialized to cJSON object
 * @return prodaq_err_t err code
 */
prodaq_err_t tcp_status_to_json(PRODAQ_TO_JSON_PARAMETERS(tcp_status_t));

#ifdef __cplusplus
}
#endif

#endif  //!__TCP_STATUS__H__