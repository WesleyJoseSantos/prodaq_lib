/**
 * @file prodaq_server.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __PRODAQ_SERVER__H__
#define __PRODAQ_SERVER__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "prodaq_message.h"
#include "prodaq_err.h"

/**
 * @brief Start the prodaq_server server.
 * 
 * @param endpoint The server endpoint.
 * @return prodaq_err_t Error code
 */
prodaq_err_t prodaq_server_start(int port, char *endpoint);

/**
 * @brief Server task, that handles clients requisitions
 * 
 * @return prodaq_err_t Error code
 */
prodaq_err_t prodaq_server_task(void);

/**
 * @brief Stop the prodaq_server server.
 * @return prodaq_err_t Error code
 */
prodaq_err_t prodaq_server_stop(void);

/**
 * @brief Set the callback to be executed when a POST request is received.
 * 
 * @param callback The callback function to be executed.
 */
void prodaq_server_on_request(prodaq_err_t (*callback)(message_t *));

/**
 * @brief Set the prodaq_server response to be sent to the client.
 * 
 * @param body The body of the response.
 */
void prodaq_server_set_response(message_t *message);

#ifdef __cplusplus
}
#endif

#endif  //!__PRODAQ_SERVER__H__