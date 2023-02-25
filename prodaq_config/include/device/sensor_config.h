/**
 * @file sensor_config.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __SENSOR_CONFIG__H__
#define __SENSOR_CONFIG__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <inttypes.h>
#include "prodaq_json.h"

/**
 * @brief Sensor types
 *
 */
typedef enum
{
    SENSOR_DATA_TYPE_TEMPERATURE, // Temperature sensor
    SENSOR_DATA_TYPE_HUMIDITY,    // Humidity sensor
    SENSOR_DATA_TYPE_VIBRATION,   // Vibration sensor
    // ...
} sensor_data_type_t;

/**
 * @brief Sensor hardware types
 *
 */
typedef enum
{
    SENSOR_HW_INVALID = 0, // Invalid hardware type
    SENSOR_HW_DHT22,       // DHT22 temperature and humidity sensor
    SENSOR_HW_HCSR04,      // HCSR04 ultrasonic sensor
    SENSOR_HW_HX711,       // HX711 load cell amplifier
    // ...
} sensor_hardware_t;

/**
 * @brief Sensor configuration
 *
 */
typedef struct
{
    uint32_t id;                  // ID that identify sensor
    uint16_t interval;            // Interval in seconds between sensor readings
    uint16_t resolution;          // Sensor resolution
    uint16_t samples;             // Number of samples to be collected before sending data
    sensor_data_type_t data_type; // Type of data that the sensor will acquire
    sensor_hardware_t hardware;   // Type of hardware the sensor is using
} sensor_config_t;

/**
 * @brief Serialize an sensor_config_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t sensor_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(sensor_config_t));

/**
 * @brief Deserialize an sensor_config_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t sensor_config_to_json(PRODAQ_TO_JSON_PARAMETERS(sensor_config_t));

#ifdef __cplusplus
}
#endif

#endif  //!__SENSOR_CONFIG__H__