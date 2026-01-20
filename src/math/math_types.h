#pragma once
#include "common/defines.h"

// 2 elements f32 vector, elements are accessable either as a 2-length array or as the fields of a struct.
// You can access the fields either as v.x, v.y or as v.r, v.b (geometric x,y or r,g from rgb)
typedef union vec2_union {
    f32 elements[2];
    struct {
        union {
            f32 x, r;
        };
        union {
            f32 y, g;
        };
    };
} vec2;

// 3 elements f32 vector. 
typedef union vec3_union {
    f32 elements[3];
    struct {
        union {
            f32 x, r;
        };
        union {
            f32 y, g;
        };
        union {
            f32 z, b;
        };
    };
} vec3;

// 4 elements f32 vector
typedef union vec4_union {
    f32 elements[4];
    struct {
        union {
            f32 x, r;
        };
        union {
            f32 y, g;
        };
        union {
            f32 z, b;
        };
        union {
            f32 w, a;
        };
    };
} vec4;

// Quaternion to represent rotational orientations
typedef vec4 quaternion;

typedef struct triangle_t {
    vec3 verts[3];
} triangle;

typedef union mat4_union {
    f32 data[16];
} mat4;

typedef union mat3_union {
    f32 data[9];
} mat3;

