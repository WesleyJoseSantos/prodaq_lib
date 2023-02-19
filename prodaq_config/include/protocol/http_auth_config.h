/**
 * @file protocol_http_auth.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __PROTOCOL_HTTP_AUTH__H__
#define __PROTOCOL_HTTP_AUTH__H__

#include <inttypes.h>
#include "prodaq_json.h"

/**
 * @brief HTTP authentication modes
 *
 */
typedef enum
{
    PROTOCOL_HTTP_AUTH_TYPE_NONE,   // No authentication
    PROTOCOL_HTTP_AUTH_TYPE_BASIC,  // HTTP Basic authentication
    PROTOCOL_HTTP_AUTH_TYPE_DIGEST, // HTTP Digest authentication
    PROTOCOL_HTTP_AUTH_TYPE_TOKEN,  // HTTP Token authentication
} http_auth_type_t;

/**
 * @brief HTTP authentication data
 *
 */
typedef struct protocol_http_auth
{
    uint8_t auth_type; // Auth type
    char username[32]; // Auth username
    char password[32]; // Auth password
    char *token;       // Auth token
} http_auth_config_t;

/**
 * @brief Serialize an http_auth_config_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t http_auth_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(http_auth_config_t));

/**
 * @brief Deserialize an http_auth_config_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t http_auth_config_to_json(PRODAQ_TO_JSON_PARAMETERS(http_auth_config_t));

#endif  //!__PROTOCOL_HTTP_AUTH__H__