/**
 * @file hardware_uart.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "uart_config.h"

prodaq_err_t uart_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(uart_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER(num);
    PRODAQ_FROM_JSON_NUMBER(baud_rate);
    PRODAQ_FROM_JSON_NUMBER(data_bits);
    PRODAQ_FROM_JSON_NUMBER(parity);
    PRODAQ_FROM_JSON_NUMBER(stop_bits);
    PRODAQ_FROM_JSON_NUMBER(flow_ctrl);
    PRODAQ_FROM_JSON_NUMBER(rx_flow_ctrl_thresh);
    return PRODAQ_OK;
}

prodaq_err_t uart_config_to_json(PRODAQ_TO_JSON_PARAMETERS(uart_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER(num);
    PRODAQ_TO_JSON_NUMBER(baud_rate);
    PRODAQ_TO_JSON_NUMBER(data_bits);
    PRODAQ_TO_JSON_NUMBER(parity);
    PRODAQ_TO_JSON_NUMBER(stop_bits);
    PRODAQ_TO_JSON_NUMBER(flow_ctrl);
    PRODAQ_TO_JSON_NUMBER(rx_flow_ctrl_thresh);
    return PRODAQ_OK;
}
