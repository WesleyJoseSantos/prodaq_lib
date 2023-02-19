cmake_minimum_required(VERSION 3.0.0)
project(prodaq_server LANGUAGES C VERSION 0.1.0)

include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/prodaq_config/lib)
include_directories(${CMAKE_SOURCE_DIR}/prodaq_config/include)
include_directories(${CMAKE_SOURCE_DIR}/prodaq_config/include/device)
include_directories(${CMAKE_SOURCE_DIR}/prodaq_config/include/hardware)
include_directories(${CMAKE_SOURCE_DIR}/prodaq_config/include/protocol)
include_directories(../cJSON)

add_subdirectory(test)

add_library(prodaq_server
    src/win/prodaq_server.c
    src/prodaq_http.c
)

add_executable(prodaq_server_windows
    examples/prodaq_server_win.c
)

target_link_libraries(prodaq_server prodaq_config)
target_link_libraries(prodaq_server ws2_32)

target_link_libraries(prodaq_server_windows prodaq_server)
target_link_libraries(prodaq_server_windows ws2_32)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
