/**
 * @file protocol_http.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __PROTOCOL_HTTP__H__
#define __PROTOCOL_HTTP__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <inttypes.h>
#include "http_auth_config.h"

/**
 * @brief HTTP Client transport
 */
typedef enum
{
    PROTOCOL_HTTP_TRANSPORT_UNKNOWN = 0x0, // Unknown
    PROTOCOL_HTTP_TRANSPORT_OVER_TCP,      // Transport over tcp
    PROTOCOL_HTTP_TRANSPORT_OVER_SSL,      // Transport over ssl
} http_transport_t;

typedef struct
{
    int port;                    // HTTP request port
    char url[128];               // HTTP request url
    char cert_file[32];          // HTTP request cert filename
    uint8_t transport_type;      // HTTP transport type
    http_auth_config_t auth; // HTTP request authentication data
} http_config_t;

/**
 * @brief Serialize an http_config_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t http_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(http_config_t));

/**
 * @brief Deserialize an http_config_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t http_config_to_json(PRODAQ_TO_JSON_PARAMETERS(http_config_t));

#ifdef __cplusplus
}
#endif

#endif //!__PROTOCOL_HTTP__H__