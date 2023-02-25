/**
 * @file hardware_ethernet.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __HARDWARE_ETHERNET__H__
#define __HARDWARE_ETHERNET__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "ip_config.h"
#include "prodaq_json.h"

/**
 * @brief Ethernet configuration
 *
 */
typedef struct
{
    ip_config_t ip; // IP configuration
} ethernet_config_t;

/**
 * @brief Serialize an ethernet_config_t object to cJSON object
 *
 * @return prodaq_err_t err code
 */
prodaq_err_t ethernet_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(ethernet_config_t));

/**
 * @brief Deserialize an ethernet_config_t object using an cJSON object
 *
 * @param type
 * @return prodaq_err_t err code
 */
prodaq_err_t ethernet_config_to_json(PRODAQ_TO_JSON_PARAMETERS(ethernet_config_t));

#ifdef __cplusplus
}
#endif

#endif //!__HARDWARE_ETHERNET__H__