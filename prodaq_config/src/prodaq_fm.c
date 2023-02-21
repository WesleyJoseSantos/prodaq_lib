/**
 * @file prodaq_fm.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "prodaq_fm.h"
#include <stdio.h>
#include <string.h>

prodaq_err_t prodaq_fm_save(void *data, size_t size, const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(data, size, 1, file);
        fclose(file);
        return PRODAQ_OK;
    } else {
       return PRODAQ_ERR_WRITE_OPERATION_FAILED;
    }
}

prodaq_err_t prodaq_fm_load(void *data, size_t size, const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file != NULL) {
        long file_size = 0;

        fseek(file, 0, SEEK_END);
        file_size = ftell(file);
        fseek(file, 0, SEEK_SET);

        if (file_size == (long)size) {
            memset(data, 0, size);
            fread(data, size, 1, file);
            fclose(file);
            return PRODAQ_OK;
        } else {
            fclose(file);
            return PRODAQ_ERR_INVALID_SIZE;
        }
    } else {
        return PRODAQ_ERR_NOT_FOUND;
    }
}
