/**
 * @file prodaq_app_win.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "prodaq_app.h"

int main(void)
{
    PRODAQ_ERROR_RETURN(prodaq_app_start());

    while (true)
    {
        PRODAQ_ERROR_RETURN(prodaq_app_task());
    }

    return PRODAQ_OK;
}
