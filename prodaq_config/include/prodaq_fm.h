/**
 * @file prodaq_fm.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __PRODAQ_FM__H__
#define __PRODAQ_FM__H__

#include "prodaq_err.h"
#include <stdlib.h>

/**
 * @brief Save file to prodaq fm
 * 
 * @param data Data to be saved
 * @param file_name Data size
 * @param file_name File name
 * @return prodaq_err_t 
 */
prodaq_err_t prodaq_fm_save(void *data, size_t size, const char *filename);

/**
 * @brief Load file from prodaq fm
 * 
 * @param data Data to be loaded
 * @param size 
 * @param flie_name 
 * @return prodaq_err_t 
 */
prodaq_err_t prodaq_fm_load(void *data, size_t size, const char *filename);

#endif  //!__PRODAQ_FM__H__