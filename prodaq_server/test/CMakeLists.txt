cmake_minimum_required(VERSION 3.10)

project(prodaq_server_tests C)

enable_testing()

include_directories(include)
include_directories(lib)
include_directories(../include)
include_directories(../../Unity/src)

add_executable(prodaq_server_tests 
    src/pc/prodaq_server_test.c
    src/main.c
    src/prodaq_http_test.c
    ../../Unity/src/unity.c
)

target_link_libraries(prodaq_server_tests ws2_32)
target_link_libraries(prodaq_server_tests prodaq_server)
