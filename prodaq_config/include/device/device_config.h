/**
 * @file device_config.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __DEVICE_CONFIG__H__
#define __DEVICE_CONFIG__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "sensor_config.h"
#include "gateway_config.h"
#include "datalogger_config.h"
#include "prodaq_json.h"

typedef enum
{
    DEVICE_SENSOR = 1,
    DEVICE_GATEWAY,
    DEVICE_DATALOGGER,
} device_t;

typedef union
{
    sensor_config_t sensor;         // Sensor configuration
    gateway_config_t gateway;       // Gateway configuration
    datalogger_config_t datalogger; // Datalogger configuration
} device_config_t;

/**
 * @brief Serialize an device_config_t object to cJSON object
 *
 * @return prodaq_err_t err code
 */
prodaq_err_t device_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(device_config_t), device_t type);

/**
 * @brief Deserialize an device_config_t object using an cJSON object
 *
 * @param type Protocol config that will be serialized to cJSON object
 * @return prodaq_err_t err code
 */
prodaq_err_t device_config_to_json(PRODAQ_TO_JSON_PARAMETERS(device_config_t), device_t type);

#ifdef __cplusplus
}
#endif

#endif //!__DEVICE_CONFIG__H__