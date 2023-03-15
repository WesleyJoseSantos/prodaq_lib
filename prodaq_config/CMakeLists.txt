cmake_minimum_required(VERSION 3.10)

project(prodaq_config C)

include_directories(include)

include_directories(../cJSON)

add_subdirectory(test)

add_library(${PROJECT_NAME}
    src/device/datalogger_config.c
    src/device/device_config.c
    src/device/device_message.c
    src/device/sensor_config.c
    src/device/gateway_config.c
    src/hardware/ethernet_config.c
    src/hardware/hardware_config.c
    src/hardware/hardware_message.c
    src/hardware/ip_config.c
    src/hardware/uart_config.c
    src/hardware/wifi_config.c

    src/info/hardware_info.c

    src/protocol/http_auth_config.c
    src/protocol/http_config.c
    src/protocol/mqtt_config.c
    src/protocol/ntp_config.c
    src/protocol/protocol_config.c
    src/protocol/protocol_message.c

    src/status/ble_status.c
    src/status/network_status.c
    src/status/tcp_status.c
    src/status/wifi_status.c

    src/prodaq_fm.c
    src/prodaq_message_data.c
    src/prodaq_message.c
    src/prodaq_request.c
    src/prodaq_response.c
    
    ../cJSON/cJSON.c
)
