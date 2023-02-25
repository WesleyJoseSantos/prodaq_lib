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

#ifdef __cplusplus
extern "C"
{
#endif

#include "prodaq_err.h"
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Saves the specified data to a file with the specified filename.
 *
 * This function takes a pointer to a block of data, the size of the data in bytes, and the filename to use for the
 * saved file as input. The function saves the data to a file with the specified filename. The function returns a
 * PRODAQ error code indicating whether the operation was successful or not.
 *
 * @param data Pointer to the block of data to save to the file.
 * @param size The size of the data block in bytes.
 * @param filename The filename to use for the saved file.
 *
 * @return A PRODAQ error code indicating whether the operation was successful or not.
 */
prodaq_err_t prodaq_fm_save(void *data, size_t size, const char *filename);

/**
 * @brief Loads data from a file with the specified filename into the specified data buffer.
 *
 * This function takes a pointer to a buffer to hold the loaded data, the size of the buffer in bytes, and the filename
 * of the file to load the data from as input. The function loads the data from the specified file into the buffer.
 * The function returns a PRODAQ error code indicating whether the operation was successful or not.
 *
 * @param data Pointer to the buffer to hold the loaded data.
 * @param size The size of the buffer in bytes.
 * @param filename The filename of the file to load the data from.
 *
 * @return A PRODAQ error code indicating whether the operation was successful or not.
 */
prodaq_err_t prodaq_fm_load(void *data, size_t size, const char *filename);

/**
 * @brief Disables or enables saving data to file.
 *
 * This function takes a boolean value as input to enable or disable saving data to file. If the input is true, data saving
 * is disabled, and if the input is false, data saving is enabled. 
 *
 * @param disable A boolean value to enable or disable data saving to file.
 *
 * @return None.
 */
void prodaq_fm_disable_save(bool disable);

#ifdef __cplusplus
}
#endif

#endif  //!__PRODAQ_FM__H__