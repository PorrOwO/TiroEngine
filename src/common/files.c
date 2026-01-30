#include "files.h"
#include <stdio.h>
#include <stdlib.h>

IOStatus file_read_buffer(char* buffer, const char* fpath, u32 max_buffer_len){
    FILE *fp = fopen(fpath, "r");
    if (fp == NULL) {
        buffer[0] = '\0';
        return IO_ERROR_OPEN;
    }
    
    size_t newLen = fread(buffer, sizeof(char), max_buffer_len - 1, fp);
    if ( ferror( fp ) != 0 ) {
        fclose(fp);
        buffer[0] = '\0';
        return IO_ERROR_READ;
    }
    
    buffer[newLen] = '\0';
    fclose(fp);
    return IO_SUCCESS;
}


IOStatus file_read_all(string_t* buffer, const char* fpath) {
    if (!buffer) return IO_ERROR_MEMORY;

    FILE* fp = fopen(fpath, "r");
    if(fp == NULL) {
        return IO_ERROR_OPEN;
    }

    fseek(fp, 0, SEEK_END);
    u32 length = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    if (length == 0) {
        fclose(fp);
        return IO_ERROR_EMPTY;
    }

    buffer->data = (char*)malloc((length + 1) * sizeof(char));
    if(!buffer->data) {
        fclose(fp);
        return IO_ERROR_MEMORY;
    }

    size_t read_size = fread(buffer->data, 1, length, fp);
    buffer->data[read_size] = '\0';
    buffer->size = read_size;
    if (read_size != length) {
        return IO_ERROR_READ;
    }

    return IO_SUCCESS;
}
