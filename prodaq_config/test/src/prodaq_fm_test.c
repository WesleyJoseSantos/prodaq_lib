/**
 * @file prodaq_fm_test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "prodaq_fm.h"
#include "unity.h"

#define PRODAQ_TEST_FILENAME "test.bin"

void prodaq_fm_save_test(void) {
    // Given
    char data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    size_t size = sizeof(data);
    prodaq_err_t result;

    // When
    result = prodaq_fm_save(data, size, PRODAQ_TEST_FILENAME);

    // Then
    TEST_ASSERT_EQUAL(PRODAQ_OK, result);
}

void prodaq_fm_load_test(void) {
    // Given
    char data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    size_t size = sizeof(data);
    prodaq_err_t result;
    char loaded_data[size];

    // When
    result = prodaq_fm_load(loaded_data, size, PRODAQ_TEST_FILENAME);

    // Then
    TEST_ASSERT_EQUAL(PRODAQ_OK, result);
    TEST_ASSERT_EQUAL_HEX8_ARRAY(data, loaded_data, size);
}
