#pragma once
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>

#include "../math/linalg.h"

enum Camera_Movement{
    FORWARD  = 0,
    BACKWARD = 1,
    LEFT     = 2,
    RIGHT    = 3
};

const f32 YAW         = -90.0f;
const f32 PITCH       = 0.0f;
const f32 SPEED       = 2.5f;
const f32 SENSITIVITY = 0.1f;
const f32 ZOOM        = 45.0f;

typedef struct Camera_t {
    vec3 Position;
    vec3 Front;
    vec3 Up;
    vec3 Right;
    vec3 WorldUp;
    //euler angles
    f32 Yaw;
    f32 Pitch;
    //camera options
    f32 MovementSpeed;
    f32 MouseSensitivity;
    f32 Zoom;
} Camera;

// initialize and returns a camera struct
Camera camera_new(vec3 pos, vec3 up, f32 yaw, f32 pitch);
// returns the view matrix given a camera
mat4 camera_get_view_matrix(Camera cam);
// update the camera vectors
void camera_update_vectors(Camera* cam);

// handle keyboard and mouse inputs 
void camera_process_keyboard(Camera* cam, int direction, f32 deltaTime);
void camera_process_mouse_movement(Camera* cam, f32 x_offset, f32 y_offset, GLboolean constrain_pitch);
void camera_process_mouse_scroll(Camera* cam, f32 y_offset);

