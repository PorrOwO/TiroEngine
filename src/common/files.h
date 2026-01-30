#pragma once
#include <stdio.h>
#include "common/defines.h"

typedef enum {
    IO_SUCCESS      =  0,
    IO_ERROR_OPEN   = -1,
    IO_ERROR_READ   = -2,
    IO_ERROR_MEMORY = -3,
    IO_ERROR_EMPTY  = -4,
} IOStatus;

// If 'call' is not SUCCESS, print error and return the error code.
#define IO_CHECK(call) \
    do { \
        IOStatus res = (call); \
        if (res != IO_SUCCESS) { \
            fprintf(stderr, "[IO ERROR] Code %d at %s:%d\n", res, __FILE__, __LINE__); \
            return res; \
        } \
    } while (0)

/* read content of a file and save it in a fixed length buffer */
IOStatus file_read_buffer(char* buffer, const char* fpath, u32 max_buffer_len);

/* read the whole content of a file and return a new string_t with the content */
IOStatus file_read_all(string_t* buffer, const char* fpath);
