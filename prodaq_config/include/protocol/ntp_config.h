/**
 * @file protocol_ntp.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __PROTOCOL_NTP__H__
#define __PROTOCOL_NTP__H__

#include <inttypes.h>
#include "prodaq_json.h"

/**
 * @brief NTP client configuration
 *
 */
typedef struct
{
    uint8_t op_mode;        // NTP operation mode
    uint32_t sync_interval; // NTP sync interval
    uint8_t sync_mode;      // NTP sync mode
    char server1[128];      // NTP server 1 url
    char server2[128];      // NTP server 2 url
    char server3[128];      // NTP server 3 url
} ntp_config_t;

/**
 * @brief Serialize an ntp_config_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t ntp_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(ntp_config_t));

/**
 * @brief Deserialize an ntp_config_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t ntp_config_to_json(PRODAQ_TO_JSON_PARAMETERS(ntp_config_t));

#endif //!__PROTOCOL_NTP__H__