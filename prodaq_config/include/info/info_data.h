/**
 * @file info_data.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __INFO_DATA__H__
#define __INFO_DATA__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "hardware_info.h"

typedef enum
{
    INFO_HARDWARE,
} info_type_t;

typedef union
{
    hardware_info_t hardware;
} info_data_t;

/**
 * @brief Serialize an info_data_t object to cJSON object
 * 
 * @return prodaq_err_t err code
 */
prodaq_err_t info_data_from_json(PRODAQ_FROM_JSON_PARAMETERS(info_data_t), info_type_t type);

/**
 * @brief Deserialize an info_data_t object using an cJSON object
 * 
 * @param type 
 * @return prodaq_err_t err code
 */
prodaq_err_t info_data_to_json(PRODAQ_TO_JSON_PARAMETERS(info_data_t), info_type_t type);

#ifdef __cplusplus
}
#endif

#endif  //!__INFO_DATA__H__