/**
 * @file hardwre_ip.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __HARDWRE_IP__H__
#define __HARDWRE_IP__H__

#include <inttypes.h>
#include <stdbool.h>
#include "prodaq_json.h"

/**
 * @brief IP configuration
 *
 */
typedef struct
{
    bool enabled;       // Enable IP configuration
    uint8_t address[4]; // Device IP address
    uint8_t mask[4];    // Network IP mask
    uint8_t gateway[4]; // Network Gateway IP
    uint8_t dns[4];     // Network DNS IP
} ip_config_t;

/**
 * @brief Serialize an ip_config_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t ip_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(ip_config_t));

/**
 * @brief Deserialize an ip_config_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t ip_config_to_json(PRODAQ_TO_JSON_PARAMETERS(ip_config_t));

#endif //!__HARDWRE_IP__H__