/**
 * @file hardware_uart.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __HARDWARE_UART__H__
#define __HARDWARE_UART__H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <inttypes.h>
#include "prodaq_json.h"

/**
 * @brief UART mode selection
 */
typedef enum
{
    PRODAQ_UART_MODE_UART = 0x00,                   /*!< mode: regular UART mode*/
    PRODAQ_UART_MODE_RS485_HALF_DUPLEX = 0x01,      /*!< mode: half duplex RS485 UART mode control by RTS pin */
    PRODAQ_UART_MODE_IRDA = 0x02,                   /*!< mode: IRDA  UART mode*/
    PRODAQ_UART_MODE_RS485_COLLISION_DETECT = 0x03, /*!< mode: RS485 collision detection UART mode (used for test purposes)*/
    PRODAQ_UART_MODE_RS485_APP_CTRL = 0x04,         /*!< mode: application control RS485 UART mode (used for test purposes)*/
} prodaq_uart_mode_t;

/**
 * @brief UART word length constants
 */
typedef enum
{
    PRODAQ_UART_DATA_5_BITS = 0x0, /*!< word length: 5bits*/
    PRODAQ_UART_DATA_6_BITS = 0x1, /*!< word length: 6bits*/
    PRODAQ_UART_DATA_7_BITS = 0x2, /*!< word length: 7bits*/
    PRODAQ_UART_DATA_8_BITS = 0x3, /*!< word length: 8bits*/
    PRODAQ_UART_DATA_BITS_MAX = 0x4,
} prodaq_uart_word_length_t;

/**
 * @brief UART stop bits number
 */
typedef enum
{
    PRODAQ_UART_STOP_BITS_1 = 0x1,   /*!< stop bit: 1bit*/
    PRODAQ_UART_STOP_BITS_1_5 = 0x2, /*!< stop bit: 1.5bits*/
    PRODAQ_UART_STOP_BITS_2 = 0x3,   /*!< stop bit: 2bits*/
    PRODAQ_UART_STOP_BITS_MAX = 0x4,
} prodaq_uart_stop_bits_t;

/**
 * @brief UART parity constants
 */
typedef enum
{
    PRODAQ_UART_PARITY_DISABLE = 0x0, /*!< Disable UART parity*/
    PRODAQ_UART_PARITY_EVEN = 0x2,    /*!< Enable UART even parity*/
    PRODAQ_UART_PARITY_ODD = 0x3      /*!< Enable UART odd parity*/
} prodaq_uart_parity_t;

/**
 * @brief UART hardware flow control modes
 */
typedef enum
{
    PRODAQ_UART_HW_FLOWCTRL_DISABLE = 0x0, /*!< disable hardware flow control*/
    PRODAQ_UART_HW_FLOWCTRL_RTS = 0x1,     /*!< enable RX hardware flow control (rts)*/
    PRODAQ_UART_HW_FLOWCTRL_CTS = 0x2,     /*!< enable TX hardware flow control (cts)*/
    PRODAQ_UART_HW_FLOWCTRL_CTS_RTS = 0x3, /*!< enable hardware flow control*/
    PRODAQ_UART_HW_FLOWCTRL_MAX = 0x4,
} prodaq_uart_hw_flowcontrol_t;

/**
 * @brief UART configuration parameters for uart_param_config function
 */
typedef struct
{
    uint8_t num;                            /*!< UART port number*/
    int baud_rate;                          /*!< UART baud rate*/
    prodaq_uart_word_length_t data_bits;    /*!< UART byte size*/
    prodaq_uart_parity_t parity;            /*!< UART parity mode*/
    prodaq_uart_stop_bits_t stop_bits;      /*!< UART stop bits*/
    prodaq_uart_hw_flowcontrol_t flow_ctrl; /*!< UART HW flow control mode (cts/rts)*/
    uint8_t rx_flow_ctrl_thresh;            /*!< UART HW RTS threshold*/
} uart_config_t;

/**
 * @brief Serialize an PRODAQ_uart_config_t object to cJSON object
 *
 * @return prodaq_err_t err code
 */
prodaq_err_t uart_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(uart_config_t));

/**
 * @brief Deserialize an PRODAQ_uart_config_t object using an cJSON object
 *
 * @param type
 * @return prodaq_err_t err code
 */
prodaq_err_t uart_config_to_json(PRODAQ_TO_JSON_PARAMETERS(uart_config_t));

#ifdef __cplusplus
}
#endif

#endif //!__HARDWARE_UART__H__