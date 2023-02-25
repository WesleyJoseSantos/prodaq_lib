/**
 * @file prodaq_protocol.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __PRODAQ_PROTOCOL__H__
#define __PRODAQ_PROTOCOL__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "prodaq_err.h"
#include "prodaq_err.h"
#include "prodaq_message.h"
#include "protocol/protocol_message.h"

/**
 * @brief Sets the configuration of the protocol based on the provided protocol message.
 *
 * This function takes a pointer to a protocol message as input and sets the configuration of the protocol
 * based on the information contained in the message. The function returns a PRODAQ error code indicating whether
 * the operation was successful or not.
 *
 * @param config Pointer to a protocol message containing the configuration information.
 *
 * @return A PRODAQ error code indicating whether the operation was successful or not.
 */
prodaq_err_t prodaq_protocol_set_config(protocol_message_t *config);

/**
 * @brief Retrieves the configuration of the PRODAQ protocol and stores it in the provided protocol message.
 *
 * This function takes a pointer to a protocol message as input and retrieves the configuration of the PRODAQ protocol,
 * storing it in the message. The function returns a PRODAQ error code indicating whether the operation was successful or not.
 *
 * @param config Pointer to a protocol message where the retrieved configuration will be stored.
 *
 * @return A PRODAQ error code indicating whether the operation was successful or not.
 */
prodaq_err_t prodaq_protocol_get_config(protocol_message_t *config);

/**
 * @brief Define a response to be sent by the protocols task.
 *
 * This function is used by the main task application to define a response to a request received by the MQTT protocol.
 *
 * @param response Pointer to the message containing the response to be sent.
 */
void prodaq_protocol_mqtt_set_response(message_t *response);

/**
 * @brief Executes the background tasks related to active protocols, such as configuration, NTP, and MQTT messages.
 *
 * This function executes the background tasks of the active protocols.
 *
 * @return A PRODAQ error code indicating whether the operation was successful or not.
 */
prodaq_err_t prodaq_protocol_task(void);

#ifdef __cplusplus
}
#endif

#endif  //!__PRODAQ_PROTOCOL__H__