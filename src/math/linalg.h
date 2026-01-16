#include "math_types.h"
#include <assert.h>
#include <math.h>

// Create and returns a 2-length vector given the 2 values
vec2 vec2_new(f32 x, f32 y){ return (vec2){x, y}; }
// Create and returns a 2-length vector with all values set to 0
vec2 vec2_zero(void){ return (vec2){0.0f, 0.0f}; }
// Create and returns a 2-length vector with all values set to 1
vec2 vec2_one(void){ return (vec2){1.0f, 1.0f}; }
// Create and returns a 2-length vector pointing up (0, 1)
vec2 vec2_up(void){ return (vec2){0.0f, 1.0f}; }
// Create and returns a 2-length vector pointing down (0, -1)
vec2 vec2_down(void){ return (vec2){0.0f, -1.0f}; }
// Create and returns a 2-length vector pointing left (-1, 0)
vec2 vec2_left(void){ return (vec2){-1.0f, 0.0f}; }
// Create and returns a 2-length vector with all right (1, 0)
vec2 vec2_right(void){ return (vec2){1.0f, 0.0f}; }

// Sum 2 vec2 and returns a copy of the result
vec2 vec2_sum(vec2 v1, vec2 v2) {
    return (vec2){v1.x + v2.x, v1.y + v2.y};
}
// Subtract 2 v2 from v1 and returns a copy of the result
vec2 vec2_sub(vec2 v1, vec2 v2) {
    return (vec2){v1.x - v2.x, v1.y - v2.y};
}

// Multiply 2 vec2 and returns a copy of the result
vec2 vec2_mul(vec2 v1, vec2 v2) {
    return (vec2){v1.x * v2.x, v1.y * v2.y};
}

// Multiply all elements of v by the given scalar and returns a copy of the result
vec2 vec2_mul_scalar(vec2 v, f32 t) {
    return (vec2){t * v.x, t * v.y};
}
// Divide v1 by v2 and returns a copy of the result
vec2 vec2_div(vec2 v1, vec2 v2) {
    assert(v2.x != 0 && v2.y != 0);
    return (vec2){v1.x / v2.x, v1.y / v2.y};  //Praying i won't divide by 0 lol, putting an assert just to be sure, will think about it
}
// returns the squared length of v
f32 vec2_length_squared(vec2 v) {
    return v.x * v.x + v.y * v.y;
}
// returns the length of v
f32 vec2_length(vec2 v) {
    return sqrt(vec2_length_squared(v));
}
// Normalize in place the provided vec2 v
void vec2_normalize(vec2* v) {
    f32 length = vec2_length(*v);
    v->x /= length;
    v->y /= length;
}
// returns a normalized copy of the provided vec2
vec2 vec2_normalized(vec2 v) { //structs are passed by copy by default so this works without changing the original struct :D
    vec2_normalize(&v);
    return v;
}
