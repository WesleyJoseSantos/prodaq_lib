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

#define DEVICE_JSON_PATH JSON_PATH "/device/"

#define MOCK_SENSOR_CONFIG_JSON DEVICE_JSON_PATH "sensor_config.json"
#define MOCK_SENSOR_MESSAGE_DATA_JSON DEVICE_JSON_PATH "sensor_message_data.json"
#define MOCK_SENSOR_MESSAGE_JSON DEVICE_JSON_PATH "sensor_message.json"

#define MOCK_DATALOGGER_CONFIG_JSON DEVICE_JSON_PATH "datalogger_config.json"
#define MOCK_DATALOGGER_MESSAGE_DATA_JSON DEVICE_JSON_PATH "datalogger_message_data.json"
#define MOCK_DATALOGGER_MESSAGE_JSON DEVICE_JSON_PATH "datalogger_message.json"

#define MOCK_GATEWAY_CONFIG_JSON DEVICE_JSON_PATH "gateway_config.json"
#define MOCK_GATEWAY_MESSAGE_DATA_JSON DEVICE_JSON_PATH "gateway_message_data.json"
#define MOCK_GATEWAY_MESSAGE_JSON DEVICE_JSON_PATH "gateway_message.json"

#define MOCK_SENSOR_CONFIG                         \
    {                                              \
        .id = 1234,                                \
        .interval = 60,                            \
        .resolution = 10,                          \
        .samples = 5,                              \
        .data_type = SENSOR_DATA_TYPE_TEMPERATURE, \
        .hardware = SENSOR_HW_DHT22                \
    }

#define MOCK_SENSOR_MESSAGE                        \
    {                                              \
        .id = MSG_ID_DEVICE_CONFIG,                \
        .data = {                                  \
            .device = {                            \
                .type = DEVICE_SENSOR,             \
                .enabled = true,                   \
                .config = {                        \
                    .sensor = MOCK_SENSOR_CONFIG}} \
        }                                          \
    }

#define MOCK_GATEWAY_CONFIG                 \
    {                                       \
        .id = 1234,                         \
        .data_out = {                       \
            .enabled = false,               \
            .path = "data_out_path",        \
            .interval = 10000,              \
            .format = GATEWAY_JSON_FORMAT}, \
        .health_out = {                     \
            .enabled = false,               \
            .path = "health_out_path",      \
            .interval = 5000,               \
            .format = GATEWAY_JSON_FORMAT   \
        }                                   \
    }

#define MOCK_GATEWAY_MESSAGE                         \
    {                                                \
        .id = MSG_ID_DEVICE_CONFIG,                  \
        .data = {                                    \
            .device = {                              \
                .type = DEVICE_GATEWAY,              \
                .enabled = true,                     \
                .config = {                          \
                    .gateway = MOCK_GATEWAY_CONFIG}} \
        }                                            \
    }

#define MOCK_DATALOGGER_CONFIG    \
    {                             \
        .id = 1234,               \
        .interval = 60,           \
        .file_path = "/file.dat", \
        .file_max_size = 1023     \
    }

#define MOCK_DATALOGGER_MESSAGE                         \
    {                                                   \
        .id = MSG_ID_DEVICE_CONFIG,                     \
        .data = {                                       \
            .device = {                                 \
                .type = DEVICE_DATALOGGER,              \
                .enabled = true,                        \
                .config = {                             \
                    .datalogger = MOCK_GATEWAY_CONFIG}} \
        }                                               \
    }

#endif //!__DEVICE_MOCKS__H__