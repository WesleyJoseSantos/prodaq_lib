/**
 * @file prodaq_hardware.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __PRODAQ_HARDWARE__H__
#define __PRODAQ_HARDWARE__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "prodaq_err.h"
#include "prodaq_err.h"
#include "hardware/hardware_message.h"

/**
 * @brief Sets the hardware configuration based on the provided hardware message.
 *
 * This function takes a pointer to a hardware message as input and sets the configuration of the hardware
 * based on the information contained in the message. The function returns a error code indicating whether
 * the operation was successful or not.
 *
 * @param message Pointer to a hardware message containing the configuration information.
 *
 * @return A PRODAQ error code indicating whether the operation was successful or not.
 */
prodaq_err_t prodaq_hardware_set_config(hardware_message_t *message);

/**
 * @brief Retrieves the configuration of the hardware and stores it in the provided hardware message.
 *
 * This function takes a pointer to a hardware message as input and retrieves the configuration of the hardware,
 * storing it in the message. The function returns a error code indicating whether the operation was successful or not.
 *
 * @param message Pointer to a hardware message where the retrieved configuration will be stored.
 *
 * @return A PRODAQ error code indicating whether the operation was successful or not.
 */
prodaq_err_t prodaq_hardware_get_config(hardware_message_t *message);

#ifdef __cplusplus
}
#endif

#endif  //!__PRODAQ_HARDWARE__H__