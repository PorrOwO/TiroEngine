#pragma once
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>

#include "common/defines.h"


// =============================================================
// Texture handling functions
// =============================================================

/*
* @brief load a texture from an image and generate the opengl texture id
*
* @param image_path The path were to fing the texture to load
* @return A u32 texture id
*/
u32 texture_generate(const char* image_path);

/*
* @brief bind the given texture to be used for rendering
*
* @param texture The id of the texture to bind
* @param slot The texture unit to use.
*   It is an offset that is added to GL_TEXTURE0 to calculate the unit to use,
*   it is used like this because GL_TEXTURE0 is equal to 0x84C0.
*   Example usage would be: if i want to use the unit 5 i would calle the function like
*   texture_bind(texture, 5) inside the implementatio we would have something like 
*   glActiveTexture(GL_TEXTURE0 + 5);
* @return void
*/
void texture_bind(u32 texture, u32 slot);
