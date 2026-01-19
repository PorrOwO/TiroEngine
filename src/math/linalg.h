#pragma once
#include "math_types.h"
#include <assert.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


// =============================================================
// Vector2 functions
// =============================================================

/*
* @brief Creates a new vec2 with the given x and y values.
*
* @param x The x (or r) component of the vector.
* @param y The y (or g) component of the vector.
* @return A vec2 struct initialized with the provided x and y values.
*/
static inline vec2 vec2_new(f32 x, f32 y){ return (vec2){x, y}; }

/*
* @brief Creates and returns a 2-length vector with all values set to 0.
*
* @param void
* @return A vec2 struct initialized with all values set to 0.
*/
static inline vec2 vec2_zero(void){ return (vec2){0.0f, 0.0f}; }

/*
* @brief Creates and returns a 2-length vector with all values set to 1.
*
* @param void
* @return A vec2 struct initialized with all values set to 1.
*/
static inline vec2 vec2_one(void){ return (vec2){1.0f, 1.0f}; }

/*
* @brief Creates and returns a 2-length vector pointing up 
* 
* @param void
* @return A vec2 struct initialized with the values (0, 1)
*/
static inline vec2 vec2_up(void){ return (vec2){0.0f, 1.0f}; }

/*
* @brief Creates and returns a 2-length vector pointing down 
* 
* @param void
* @return A vec2 struct initialized with the values (0, -1)
*/
static inline vec2 vec2_down(void){ return (vec2){0.0f, -1.0f}; }

/*
* @brief Creates and returns a 2-length vector pointing left 
* 
* @param void
* @return A vec2 struct initialized with the values (-1, 0)
*/
static inline vec2 vec2_left(void){ return (vec2){-1.0f, 0.0f}; }

/*
* @brief Creates and returns a 2-length vector pointing right 
* 
* @param void
* @return A vec2 struct initialized with the values (1, 0).
*/
static inline vec2 vec2_right(void){ return (vec2){1.0f, 0.0f}; }

/*
* @brief Sums two vec2 and returns a copy of the result.
* 
* @param v1 The first vector.
* @param v2 The second vector.
* @return A vec2 struct containing the sum of v1 and v2.
*/
static inline vec2 vec2_sum(vec2 v1, vec2 v2) {
    return (vec2){v1.x + v2.x, v1.y + v2.y};
}

/*
* @brief Subtracts two vec2 and returns a copy of the result.
* 
* @param v1 The first vector.
* @param v2 The second vector.
* @return A vec2 struct containing v1 - v2.
*/
static inline vec2 vec2_sub(vec2 v1, vec2 v2) {
    return (vec2){v1.x - v2.x, v1.y - v2.y};
}

/*
* @brief Multiplies two vec2 and returns a copy of the result.
* 
* @param v1 The first vector.
* @param v2 The second vector.
* @return A vec2 struct containing the element-wise product of v1 and v2.
*/
static inline vec2 vec2_mul(vec2 v1, vec2 v2) {
    return (vec2){v1.x * v2.x, v1.y * v2.y};
}

/*
* @brief Multiplies all elements of a vec2 by the given scalar and returns a copy of the result.
* 
* @param v The vector.
* @param t The scalar value.
* @return A vec2 struct containing v multiplied by t.
*/
static inline vec2 vec2_mul_scalar(vec2 v, f32 t) {
    return (vec2){t * v.x, t * v.y};
}

/*
* @brief Divides two vec2 and returns a copy of the result.
* 
* @param v1 The first vector (dividend).
* @param v2 The second vector (divisor).
* @return A vec2 struct containing v1 / v2.
*/
static inline vec2 vec2_div(vec2 v1, vec2 v2) {
    assert(v2.x != 0 && v2.y != 0);
    return (vec2){v1.x / v2.x, v1.y / v2.y};  //Praying i won't divide by 0 lol, putting an assert just to be sure, will think about it
}

/*
* @brief Returns the squared length of a vec2.
* 
* @param v The vector.
* @return The squared length of v.
*/
static inline f32 vec2_length_squared(vec2 v) {
    return v.x * v.x + v.y * v.y;
}

/*
* @brief Returns the length of a vec2.
* 
* @param v The vector.
* @return The length of v.
*/
static inline f32 vec2_length(vec2 v) {
    return sqrt(vec2_length_squared(v));
}

/*
* @brief Normalizes in place the provided vec2.
* 
* @param v Pointer to the vector to normalize.
* @return void
*/
static inline void vec2_normalize(vec2* v) {
    f32 length = vec2_length(*v);
    v->x /= length;
    v->y /= length;
}

/*
* @brief Returns a normalized copy of the provided vec2.
* 
* @param v The vector to normalize.
* @return A normalized copy of v.
*/
static inline vec2 vec2_normalized(vec2 v) { //structs are passed by copy by default so this works without changing the original struct :D
    vec2_normalize(&v);
    return v;
}


// =============================================================
// Vector3 functions
// =============================================================

/*
* @brief Creates and returns a 3-length vector given the 3 values.
* 
* @param x The x component of the vector.
* @param y The y component of the vector.
* @param z The z component of the vector.
* @return A vec3 struct initialized with the provided x, y, and z values.
*/
static inline vec3 vec3_new(f32 x, f32 y, f32 z){ return (vec3){x, y, z}; }

/*
* @brief Creates and returns a 3-length vector with all values set to 0.
*
* @param void
* @return A vec3 struct initialized with all values set to 0.
*/
static inline vec3 vec3_zero(void){ return (vec3){0.0f, 0.0f, 0.0f}; }

/*
* @brief Creates and returns a 3-length vector with all values set to 1.
*
* @param void
* @return A vec3 struct initialized with all values set to 1.
*/
static inline vec3 vec3_one(void){ return (vec3){1.0f, 1.0f, 1.0f}; }

/*
* @brief Creates and returns a 3-length vector pointing up.
*
* @param void
* @return A vec3 struct initialized with the values (0, 1, 0).
*/
static inline vec3 vec3_up(void){ return (vec3){0.0f, 1.0f, 0.0f}; }

/*
* @brief Creates and returns a 3-length vector pointing down.
*
* @param void
* @return A vec3 struct initialized with the values (0, -1, 0).
*/
static inline vec3 vec3_down(void){ return (vec3){0.0f, -1.0f, 0.0f}; }

/*
* @brief Creates and returns a 3-length vector pointing left.
*
* @param void
* @return A vec3 struct initialized with the values (-1, 0, 0).
*/
static inline vec3 vec3_left(void){ return (vec3){-1.0f, 0.0f, 0.0f}; }

/*
* @brief Creates and returns a 3-length vector pointing right.
*
* @param void
* @return A vec3 struct initialized with the values (1, 0, 0).
*/
static inline vec3 vec3_right(void){ return (vec3){1.0f, 0.0f, 0.0f}; }

/*
* @brief Creates and returns a 3-length vector pointing forward.
*
* @param void
* @return A vec3 struct initialized with the values (0, 0, 1).
*/
static inline vec3 vec3_forward(void){ return (vec3){0.0f, 0.0f, 1.0f}; }

/*
* @brief Creates and returns a 3-length vector pointing backward.
*
* @param void
* @return A vec3 struct initialized with the values (0, 0, -1).
*/
static inline vec3 vec3_backward(void){ return (vec3){0.0f, 0.0f, -1.0f}; }

/*
* @brief Sums two vec3 and returns a copy of the result.
*
* @param v1 The first vector.
* @param v2 The second vector.
* @return A vec3 struct containing the sum of v1 and v2.
*/
static inline vec3 vec3_sum(vec3 v1, vec3 v2) {
    return (vec3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

/*
* @brief Subtracts two vec3 and returns a copy of the result.
*
* @param v1 The first vector.
* @param v2 The second vector.
* @return A vec3 struct containing v1 - v2.
*/
static inline vec3 vec3_sub(vec3 v1, vec3 v2) {
    return (vec3){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

/*
* @brief Multiplies two vec3 and returns a copy of the result.
*
* @param v1 The first vector.
* @param v2 The second vector.
* @return A vec3 struct containing the element-wise product of v1 and v2.
*/
static inline vec3 vec3_mul(vec3 v1, vec3 v2) {
    return (vec3){v1.x * v2.x, v1.y * v2.y, v1.z * v2.z};
}

/*
* @brief Multiplies all elements of a vec3 by the given scalar and returns a copy of the result.
*
* @param v The vector.
* @param t The scalar value.
* @return A vec3 struct containing v multiplied by t.
*/
static inline vec3 vec3_mul_scalar(vec3 v, f32 t) {
    return (vec3){t * v.x, t * v.y, t * v.z};
}

/*
* @brief Divides two vec3 and returns a copy of the result.
*
* @param v1 The first vector (dividend).
* @param v2 The second vector (divisor).
* @return A vec3 struct containing v1 / v2.
*/
static inline vec3 vec3_div(vec3 v1, vec3 v2) {
    assert(v2.x != 0 && v2.y != 0);
    return (vec3){v1.x / v2.x, v1.y / v2.y, v1.z / v2.z};  //Praying i won't divide by 0 lol, putting an assert just to be sure, will think about it
}

/*
* @brief Returns the squared length of a vec3.
*
* @param v The vector.
* @return The squared length of v.
*/
static inline f32 vec3_length_squared(vec3 v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

/*
* @brief Returns the length of a vec3.
*
* @param v The vector.
* @return The length of v.
*/
static inline f32 vec3_length(vec3 v) {
    return sqrt(vec3_length_squared(v));
}

/*
* @brief Normalizes in place the provided vec3.
*
* @param v Pointer to the vector to normalize.
* @return void
*/
static inline void vec3_normalize(vec3* v) {
    f32 length = vec3_length(*v);
    v->x /= length;
    v->y /= length;
    v->z /= length;
}

/*
* @brief Returns a normalized copy of the provided vec3.
*
* @param v The vector to normalize.
* @return A normalized copy of v.
*/
static inline vec3 vec3_normalized(vec3 v) { //structs are passed by copy by default so this works without changing the original struct :D
    vec3_normalize(&v);
    return v;
}

/*
* @brief Returns the dot product of the two vectors provided.
* 
* @param v1 The first vector.
* @param v2 The second vector.
* @return The dot product of v1 and v2.
*/
static inline f32 vec3_dot_prod(vec3 v1, vec3 v2) {
    f32 res = v1.x * v2.x;
    res += v1.y * v2.y;
    res += v1.z * v2.z;
    return res;
}

/*
* @brief Calculates the cross product of the two vectors provided and returns a copy of the result.
* 
* @param v1 The first vector.
* @param v2 The second vector.
* @return A vec3 struct containing the cross product of v1 and v2.
*/
static inline vec3 vec3_cross_prod(vec3 v1, vec3 v2) {
    return (vec3){
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x,
    };
}


// =============================================================
// Matrix4 functions
// =============================================================

/*
* @brief Creates and returns an identity matrix.
* 
* @param void
* @return A mat4 struct initialized as an identity matrix.
*/
static inline mat4 mat4_identity(void) {
    mat4 res;
    memset(res.data, 0, sizeof(f32) * 16); // initialize all values to 0;
    res.data[0] = 1.0f;
    res.data[5] = 1.0f;
    res.data[10] = 1.0f;
    res.data[15] = 1.0f;
    return res;
}

/*
* @brief Multiplies two mat4 and returns the resulting matrix.
* 
* @param m1 The first matrix.
* @param m2 The second matrix.
* @return A mat4 struct containing the product of m1 and m2.
*/
static inline mat4 mat4_mul(mat4 m1, mat4 m2) {
    mat4 res = mat4_identity();

    const f32* m1_ptr = m1.data;
    const f32* m2_ptr = m2.data;
    f32* dst_ptr = res.data;

    for (i32 i = 0; i < 4; ++i) {
        for (i32 j = 0; j < 4; ++j) {
            *dst_ptr = m1_ptr[0] * m2_ptr[0 + j] + m1_ptr[1] * m2_ptr[4 + j] +
                       m1_ptr[2] * m2_ptr[8 + j] + m1_ptr[3] * m2_ptr[12 + j];
            dst_ptr++;
        }
        m1_ptr += 4;
    }
    return res;
}

/*
* @brief Creates and returns the look_at matrix.
* 
* @param pos The position of the camera.
* @param target The position to look at.
* @param up The up direction vector.
* @return A mat4 struct containing the look_at matrix.
*/
static inline mat4 mat4_look_at(vec3 pos, vec3 target, vec3 up) {
    mat4 res;
    vec3 z_axis = vec3_normalized(vec3_sub(target, pos));
    vec3 x_axis = vec3_normalized(vec3_cross_prod(z_axis, up));
    vec3 y_axis = vec3_cross_prod(x_axis, z_axis);
    
    res.data[0] = x_axis.x;
    res.data[1] = y_axis.x;
    res.data[2] = -z_axis.x;
    res.data[3] = 0;
    res.data[4] = x_axis.y;
    res.data[5] = y_axis.y;
    res.data[6] = -z_axis.y;
    res.data[7] = 0;
    res.data[8] = x_axis.z;
    res.data[9] = y_axis.z;
    res.data[10] = -z_axis.z;
    res.data[11] = 0;
    res.data[12] = -vec3_dot_prod(x_axis, pos);
    res.data[13] = -vec3_dot_prod(y_axis, pos);
    res.data[14] = vec3_dot_prod(z_axis, pos);
    res.data[15] = 1.0f;
    
    return res;
}

/*
* @brief Creates and returns the transposed matrix of the given matrix.
* 
* @param m The matrix to transpose.
* @return A mat4 struct containing the transposed matrix.
*/
static inline mat4 mat4_transposed(mat4 m) {
    mat4 res;
    res.data[0]  = m.data[0];
    res.data[1]  = m.data[4];
    res.data[2]  = m.data[8];
    res.data[3]  = m.data[12];
    res.data[4]  = m.data[1];
    res.data[5]  = m.data[5];
    res.data[6]  = m.data[9];
    res.data[7]  = m.data[13];
    res.data[8]  = m.data[2];
    res.data[9]  = m.data[6];
    res.data[10] = m.data[10];
    res.data[11] = m.data[14];
    res.data[12] = m.data[3];
    res.data[13] = m.data[7];
    res.data[14] = m.data[11];
    res.data[15] = m.data[15];
    return res;
}

/*
* @brief Calculates and returns the determinant of the given matrix.
* 
* @param m The matrix.
* @return The determinant of m.
*/
static inline f32 mat4_determinant(mat4 m) {
    const f32* m_data = m.data;
    f32 t0  = m_data[10] * m_data[15];
    f32 t1  = m_data[14] * m_data[11];
    f32 t2  = m_data[6]  * m_data[15];
    f32 t3  = m_data[14] * m_data[7];
    f32 t4  = m_data[6]  * m_data[11];
    f32 t5  = m_data[10] * m_data[7];
    f32 t6  = m_data[2]  * m_data[15];
    f32 t7  = m_data[14] * m_data[3];
    f32 t8  = m_data[2]  * m_data[11];
    f32 t9  = m_data[10] * m_data[3];
    f32 t10 = m_data[2]  * m_data[7];
    f32 t11 = m_data[6]  * m_data[3];

    mat3 temp_mat;
    f32* o = temp_mat.data;

    o[0] = (t0 * m_data[5] + t3 * m_data[9] + t4  * m_data[13]) -
           (t1 * m_data[5] + t2 * m_data[9] + t5  * m_data[13]);
    o[1] = (t1 * m_data[1] + t6 * m_data[9] + t9  * m_data[13]) -
           (t0 * m_data[1] + t7 * m_data[9] + t8  * m_data[13]);
    o[2] = (t2 * m_data[1] + t7 * m_data[5] + t10 * m_data[13]) -
           (t3 * m_data[1] + t6 * m_data[5] + t11 * m_data[13]);
    o[3] = (t5 * m_data[1] + t8 * m_data[5] + t11 * m_data[9]) -
           (t4 * m_data[1] + t9 * m_data[5] + t10 * m_data[9]);

    f32 determinant = 1.0f / (m_data[0] * o[0] + m_data[4] * o[1] + m_data[8] * o[2] + m_data[12] * o[3]);
    return determinant;
}

/*
* @brief Calculates the inverse matrix.
* 
* @param matrix The matrix to invert.
* @return A mat4 struct containing the inverse of the matrix.
*/
static inline mat4 mat4_inverse(mat4 matrix) {
    const f32* m = matrix.data;

    f32 t0  = m[10] * m[15];
    f32 t1  = m[14] * m[11];
    f32 t2  = m[6]  * m[15];
    f32 t3  = m[14] * m[7];
    f32 t4  = m[6]  * m[11];
    f32 t5  = m[10] * m[7];
    f32 t6  = m[2]  * m[15];
    f32 t7  = m[14] * m[3];
    f32 t8  = m[2]  * m[11];
    f32 t9  = m[10] * m[3];
    f32 t10 = m[2]  * m[7];
    f32 t11 = m[6]  * m[3];
    f32 t12 = m[8]  * m[13];
    f32 t13 = m[12] * m[9];
    f32 t14 = m[4]  * m[13];
    f32 t15 = m[12] * m[5];
    f32 t16 = m[4]  * m[9];
    f32 t17 = m[8]  * m[5];
    f32 t18 = m[0]  * m[13];
    f32 t19 = m[12] * m[1];
    f32 t20 = m[0]  * m[9];
    f32 t21 = m[8]  * m[1];
    f32 t22 = m[0]  * m[5];
    f32 t23 = m[4]  * m[1];

    mat4 out_matrix;
    f32* o = out_matrix.data;

    o[0] = (t0 * m[5] + t3 * m[9] + t4  * m[13]) -
           (t1 * m[5] + t2 * m[9] + t5  * m[13]);
    o[1] = (t1 * m[1] + t6 * m[9] + t9  * m[13]) -
           (t0 * m[1] + t7 * m[9] + t8  * m[13]);
    o[2] = (t2 * m[1] + t7 * m[5] + t10 * m[13]) -
           (t3 * m[1] + t6 * m[5] + t11 * m[13]);
    o[3] = (t5 * m[1] + t8 * m[5] + t11 * m[9]) -
           (t4 * m[1] + t9 * m[5] + t10 * m[9]);

    f32 d = 1.0f / (m[0] * o[0] + m[4] * o[1] + m[8] * o[2] + m[12] * o[3]);

    // Check for singular matrix (determinant near zero)
    if (abs(d) < 1e-6f) {
        // Return identity matrix if the determinant is close to zero (singular matrix)
        return mat4_identity();
    }

    o[0]  = d * o[0];
    o[1]  = d * o[1];
    o[2]  = d * o[2];
    o[3]  = d * o[3];
    o[4]  = d * ((t1 * m[4] + t2 * m[8] + t5  * m[12]) -
                (t0  * m[4] + t3 * m[8] + t4  * m[12]));
    o[5]  = d * ((t0 * m[0] + t7 * m[8] + t8  * m[12]) -
                (t1  * m[0] + t6 * m[8] + t9  * m[12]));
    o[6]  = d * ((t3 * m[0] + t6 * m[4] + t11 * m[12]) -
                (t2  * m[0] + t7 * m[4] + t10 * m[12]));
    o[7]  = d * ((t4 * m[0] + t9 * m[4] + t10 * m[8]) -
                (t5  * m[0] + t8 * m[4] + t11 * m[8]));
    o[8]  = d * ((t12 * m[7] + t15 * m[11] + t16 * m[15]) -
                (t13  * m[7] + t14 * m[11] + t17 * m[15]));
    o[9]  = d * ((t13 * m[3] + t18 * m[11] + t21 * m[15]) -
                (t12  * m[3] + t19 * m[11] + t20 * m[15]));
    o[10] = d * ((t14 * m[3] + t19 * m[7]  + t22 * m[15]) -
                 (t15 * m[3] + t18 * m[7]  + t23 * m[15]));
    o[11] = d * ((t17 * m[3] + t20 * m[7]  + t23 * m[11]) -
                 (t16 * m[3] + t21 * m[7]  + t22 * m[11]));
    o[12] = d * ((t14 * m[10] + t17 * m[14] + t13 * m[6]) -
                 (t16 * m[14] + t12 * m[6]  + t15 * m[10]));
    o[13] = d * ((t20 * m[14] + t12 * m[2]  + t19 * m[10]) -
                 (t18 * m[10] + t21 * m[14] + t13 * m[2]));
    o[14] = d * ((t18 * m[6]  + t23 * m[14] + t15 * m[2]) -
                 (t22 * m[14] + t14 * m[2]  + t19 * m[6]));
    o[15] = d * ((t22 * m[10] + t16 * m[2]  + t21 * m[6]) -
                 (t20 * m[6]  + t23 * m[10] + t17 * m[2]));

    return out_matrix;
}

/*
* @brief Creates and returns a perspective projection matrix.
* 
* @param fov The field of view angle in radians.
* @param aspect_ratio The aspect ratio of the viewport.
* @param near_clip The near clipping plane distance.
* @param far_clip The far clipping plane distance.
* @return A mat4 struct containing the perspective projection matrix.
*/
static inline mat4 mat4_perspective(f32 fov, f32 aspect_ratio, f32 near_clip, f32 far_clip) {
    f32 half_tan_fov = tan(fov * 0.5f);
    mat4 res;
    memset(res.data, 0, sizeof(f32) * 16); // initialize all values to 0;
    res.data[0] = 1.0f / (aspect_ratio * half_tan_fov);
    res.data[5] = 1.0f / half_tan_fov;
    res.data[10] = far_clip / (near_clip - far_clip);
    res.data[11] = -1.0f;
    res.data[14] = (far_clip * near_clip) / (near_clip - far_clip);
    return res;
}
