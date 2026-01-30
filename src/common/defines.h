#pragma once

#include <sys/types.h>

// OpenGL default version
#define GL_VERSION_MAJOR 4
#define GL_VERSION_MINOR 6
// Default window size
#define WINDOW_WIDTH  600
#define WINDOW_HEIGHT 600

// Types definition
typedef u_int8_t  u8;
typedef u_int16_t u16;
typedef u_int32_t u32;
typedef u_int64_t u64;

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float  f32;
typedef double f64;

// length based string type (the idea is to have it immutable after being initialized)
typedef struct {
    char* data;
    size_t size;
} string_t;


// Dynamic array types
typedef struct {
    f32* items;
    size_t count;
    size_t capacity;
} f32_darray;

typedef struct {
    u32* items;
    size_t count;
    size_t capacity;
} u32_darray;


// Dynamic array macros
#define da_append(xs, x)\
    do {\
        if(xs.count >= xs.capacity) {\
            if(xs.capacity == 0) xs.capacity = 256;\
            else xs.capacity *= 2;\
            xs.items = realloc(xs.items, xs.capacity * sizeof(*xs.items));\
        }\
        xs.items[xs.count++] = x;\
    }while(0)
