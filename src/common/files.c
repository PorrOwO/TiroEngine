#include "files.h"

i32 file_read_buffer(char* buffer, const char* fpath, u32 max_buffer_len){
    FILE *fp = fopen(fpath, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", fpath);
        buffer[0] = '\0';
        return -1;
    }
    
    size_t newLen = fread(buffer, sizeof(char), max_buffer_len - 1, fp);
    if ( ferror( fp ) != 0 ) {
        fprintf(stderr, "Error reading file '%s'\n", fpath);
        fclose(fp);
        buffer[0] = '\0';
        return -1;
    }
    
    buffer[newLen] = '\0';
    fclose(fp);
    return 0;
}
