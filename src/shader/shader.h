#pragma once

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>
#include "../common/defines.h"
#include "../common/files.h"
#include "../math/math_types.h"

#define MAXSHADERBUFLEN 1000000

u32 shader_new(const char* vertex_src, const char* fragment_src);

void shader_use(u32 shaderID);

void shader_check_compile_error(u32 shaderID, const char* type);


//void setBool(const std::string &, bool) const;
//void setInt(const std::string &, int) const;
//void setFloat(const std::string &, float) const;
//// ------------------------------------------------------------------------
//void setVec2(const std::string &name, const glm::vec2 &value) const;
//void setVec2(const std::string &name, float x, float y) const;
//// ------------------------------------------------------------------------
//void setVec3(const std::string &name, const glm::vec3 &value) const;
//void setVec3(const std::string &name, float x, float y, float z) const;
//// ------------------------------------------------------------------------
//void setVec4(const std::string &name, const glm::vec4 &value) const;
//void setVec4(const std::string &name, float x, float y, float z, float w) const;
//// ------------------------------------------------------------------------
//void setMat2(const std::string &name, const glm::mat2 &mat) const;
//// ------------------------------------------------------------------------
//void setMat3(const std::string &name, const glm::mat3 &mat) const;
//// ------------------------------------------------------------------------
void shader_set_mat4(u32 shaderID, const char* name, const mat4 mat);
