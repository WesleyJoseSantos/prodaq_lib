cmake_minimum_required(VERSION 3.0.0)
project(prodaq_app LANGUAGES C VERSION 0.1.0)

include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/prodaq_config/lib)
include_directories(${CMAKE_SOURCE_DIR}/prodaq_config/include)
include_directories(${CMAKE_SOURCE_DIR}/prodaq_config/include/device)
include_directories(${CMAKE_SOURCE_DIR}/prodaq_config/include/hardware)
include_directories(${CMAKE_SOURCE_DIR}/prodaq_config/include/protocol)
include_directories(${CMAKE_SOURCE_DIR}/prodaq_server/include)
include_directories(../cJSON)

add_library(${PROJECT_NAME} 
    src/prodaq_app.c
    src/fm/prodaq_hardware.c
    src/fm/prodaq_protocol.c
)

add_executable(prodaq_app_bin
    example/prodaq_app_bin.c
)

target_link_libraries(${PROJECT_NAME} prodaq_config)
target_link_libraries(${PROJECT_NAME} prodaq_server)
target_link_libraries(${PROJECT_NAME} Kernel32.lib)

target_link_libraries(prodaq_app_bin prodaq_app)
