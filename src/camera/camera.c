#pragma once

#include "camera/camera.h"
#include "math/math.h"
#include <math.h>

Camera camera_new(vec3 pos, vec3 up, f32 yaw, f32 pitch){
    Camera cam;
    // initializers
    cam.Front = vec3_backward();
    cam.MovementSpeed = SPEED;
    cam.MouseSensitivity = SENSITIVITY;
    cam.Zoom = ZOOM;

    cam.Position = pos;
    cam.WorldUp = up;
    cam.Yaw = yaw;
    cam.Pitch = pitch;
    camera_update_vectors(&cam);
    return cam;
}
// returns the view matrix given a camera
mat4 camera_get_view_matrix(Camera cam) {
    return mat4_look_at(cam.Position, vec3_sum(cam.Position, cam.Front), cam.Up);
}
// update the camera vectors
void camera_update_vectors(Camera* cam) {
    vec3 front;
    front.x = cos(radians(cam->Yaw)) * cos(radians(cam->Pitch));
    front.y = sin(radians(cam->Pitch));
    front.z = sin(radians(cam->Yaw)) * cos(radians(cam->Pitch));
    
    cam->Front = vec3_normalized(front);
    cam->Right = vec3_normalized(vec3_cross_prod(cam->Front, cam->WorldUp));
    cam->Up    = vec3_normalized(vec3_cross_prod(cam->Right, cam->Front));
}

// handle keyboard and mouse inputs 
void camera_process_keyboard(Camera* cam, int direction, f32 deltaTime) {
    f32 velocity = cam->MovementSpeed * deltaTime;
    if (direction == FORWARD)
        cam->Position = vec3_sum(cam->Position, vec3_mul_scalar(cam->Front, velocity));
    if (direction == BACKWARD)
        cam->Position = vec3_sub(cam->Position, vec3_mul_scalar(cam->Front, velocity));
    if (direction == LEFT)
        cam->Position = vec3_sub(cam->Position, vec3_mul_scalar(cam->Right, velocity));
    if (direction == RIGHT)
        cam->Position = vec3_sum(cam->Position, vec3_mul_scalar(cam->Right, velocity));
}

void camera_process_mouse_movement(Camera* cam, f32 x_offset, f32 y_offset, GLboolean constrain_pitch) {
    x_offset *= cam->MouseSensitivity;
    y_offset *= cam->MouseSensitivity;

    cam->Yaw   += x_offset;
    cam->Pitch += y_offset;

    if (constrain_pitch) {
        if (cam->Pitch > 89.0f)
            cam->Pitch = 89.0f;
        if (cam->Pitch < -89.0f)
            cam->Pitch = -89.0;
    }

    camera_update_vectors(cam);
}

void camera_process_mouse_scroll(Camera* cam, f32 y_offset) {
    cam->Zoom -= y_offset;
    if (cam->Zoom < 1.0f)
        cam->Zoom = 1.0f;
    if (cam->Zoom > 45.0f)
        cam->Zoom = 45.0f;
}
