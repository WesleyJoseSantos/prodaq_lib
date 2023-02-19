cmake_minimum_required(VERSION 3.0.0)
project(prodaq LANGUAGES C VERSION 0.1.0)

add_subdirectory(prodaq_config)
add_subdirectory(prodaq_server)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
