cmake_minimum_required(VERSION 3.10)

project(prodaq_config_tests C)

enable_testing()

include_directories(include)
include_directories(lib)
include_directories(../include)
include_directories(../../cJSON)
include_directories(../../Unity/src)

add_executable(${PROJECT_NAME} 
    src/main.c
    src/json.c

    src/hardware/hardware_config_test.c
    src/hardware/ethernet_config_test.c
    src/hardware/ip_config_test.c
    src/hardware/hardware_message_test.c
    src/hardware/uart_config_test.c
    src/hardware/wifi_config_test.c

    src/status/ble_status_test.c
    src/status/network_status_test.c
    src/status/tcp_status_test.c
    src/status/wifi_status_test.c

    src/device/datalogger_config_test.c
    src/device/device_config_test.c
    src/device/device_message_test.c
    src/device/gateway_config_test.c
    src/device/sensor_config_test.c

    src/protocol/http_auth_config_test.c
    src/protocol/http_config_test.c
    src/protocol/mqtt_config_test.c
    src/protocol/ntp_config_test.c
    src/protocol/protocol_config_test.c
    src/protocol/protocol_message_test.c

    src/prodaq_fm_test.c
    src/prodaq_message_data_test.c
    src/prodaq_message_test.c
    src/prodaq_request_test.c
    src/prodaq_response_test.c

    ../../cJSON/cJSON.c
    ../../Unity/src/unity.c
)

# target_link_libraries(${PROJECT_NAME} unity)
target_link_libraries(${PROJECT_NAME} prodaq_config)
