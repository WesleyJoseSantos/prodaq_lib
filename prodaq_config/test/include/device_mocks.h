/**
 * @file device_mocks.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __DEVICE_MOCKS__H__
#define __DEVICE_MOCKS__H__

#include <stdio.h>

#include "json.h"

#define DEVICE_JSON_PATH JSON_PATH "/device/"

#define MOCK_SENSOR_CONFIG_JSON DEVICE_JSON_PATH "sensor_config.json"
#define MOCK_SENSOR_MESSAGE_JSON DEVICE_JSON_PATH "sensor_message.json"

#define MOCK_SENSOR_CONFIG                         \
    {                                              \
        .id = 1234,                                \
        .interval = 60,                            \
        .resolution = 10,                          \
        .samples = 5,                              \
        .data_type = SENSOR_DATA_TYPE_TEMPERATURE, \
        .hardware = SENSOR_HW_DHT22                \
    }

#define MOCK_SENSOR_MESSAGE                                \
    {                                                      \
        .id = MSG_ID_DEVICE_CONFIG,                        \
        .data = {                                          \
            .device = {                                    \
                .id = 1234,                                \
                .interval = 60,                            \
                .resolution = 10,                          \
                .samples = 5,                              \
                .data_type = SENSOR_DATA_TYPE_TEMPERATURE, \
                .hardware = SENSOR_HW_DHT22}               \
        }                                                  \
    }

#endif //!__DEVICE_MOCKS__H__