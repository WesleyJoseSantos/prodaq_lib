/**
 * @file prodaq_device.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __PRODAQ_DEVICE__H__
#define __PRODAQ_DEVICE__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "prodaq_err.h"
#include "prodaq_err.h"
#include "prodaq_message.h"
#include "device/device_message.h"

prodaq_err_t prodaq_device_set_config(device_message_t *config);
prodaq_err_t prodaq_device_get_config(device_message_t *config);
prodaq_err_t prodaq_device_task(void);

#ifdef __cplusplus
}
#endif

#endif  //!__PRODAQ_DEVICE__H__