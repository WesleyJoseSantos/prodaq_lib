/**
 * @file prodaq_app.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __PRODAQ_APP__H__
#define __PRODAQ_APP__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "prodaq_err.h"
#include "prodaq_message.h"

/**
 * @brief Starts the ProDAQ application.
 *
 * @return ProDAQ error code indicating the success or failure of the function.
 */
prodaq_err_t prodaq_app_start(void);

/**
 * @brief 
 * 
 * @return prodaq_err_t 
 */
prodaq_err_t prodaq_app_task(void);

/**
 * @brief Sends a message to the ProDAQ application.
 *
 * @param message Pointer to the message to send.
 * @return ProDAQ error code indicating the success or failure of the function.
 */
prodaq_err_t prodaq_app_send_message(message_t *message);

/**
 * @brief Waits for a message with the specified ID to be processed by the ProDAQ application.
 *
 * @param message_id ID of the message to wait for.
 * @param timeout Maximum time to wait for the message to be processed, in milliseconds.
 * @return ProDAQ error code indicating the success or failure of the function.
 */
prodaq_err_t prodaq_app_wait_message_processing(message_id_t message_id, uint32_t timeout);

#ifdef __cplusplus
}
#endif

#endif  //!__PRODAQ_APP__H__