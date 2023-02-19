/**
 * @file json.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "json.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

cJSON *json_read_file(const char *filename) {
    FILE *fp;
    long filesize;
    char *buffer;
    size_t n_read;
    cJSON *json;

    fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    rewind(fp);

    buffer = (char *) malloc(filesize + 1);
    if (!buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        fclose(fp);
        return NULL;
    }

    n_read = fread(buffer, 1, filesize, fp);
    if (n_read != filesize) {
        fprintf(stderr, "Failed to read file %s\n", filename);
        fclose(fp);
        free(buffer);
        return NULL;
    }

    buffer[filesize] = '\0';

    json = cJSON_Parse(buffer);
    if (!json) {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL) {
            fprintf(stderr, "Error parsing JSON: %s\n", error_ptr);
        }
        fclose(fp);
        free(buffer);
        return NULL;
    }

    fclose(fp);
    free(buffer);
    return json;
}