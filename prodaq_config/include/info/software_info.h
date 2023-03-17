/**
 * @file software_info.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __SOFTWARE_INFO__H__
#define __SOFTWARE_INFO__H__

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum
{
    OS_TYPE_UNKNOWN,
    OS_TYPE_BAREMETAL,
    OS_TYPE_FREERTOS,
    OS_TYPE_ZEPHYR,
    OS_TYPE_CONTIKY,
    OS_TYPE_MBED_OS,
    OS_TYPE_TINYOS,
    OS_LINUX,
    OS_WINDOWS
} os_type;

#ifdef __cplusplus
}
#endif

#endif  //!__SOFTWARE_INFO__H__