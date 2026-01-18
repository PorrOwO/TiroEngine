#include "./shader.h"
#include <GL/glext.h>
#include <string.h>

u32 shader_new(const char* vertex_src, const char* fragment_src) {
    const u32 maxbufferlen = MAXSHADERBUFLEN + 1;
    char vertex_code[maxbufferlen];
    char fragment_code[maxbufferlen];
    
    file_read_buffer(vertex_code, vertex_src, maxbufferlen);
    file_read_buffer(fragment_code, fragment_src, maxbufferlen);

    const char* vertex_code_ptr = vertex_code;
    const char* fragment_code_ptr = fragment_code;

    u32 programID, vertex, fragment;
    
    //VERTEX SHADERS
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertex_code_ptr, NULL);
    glCompileShader(vertex);
    shader_check_compile_error(vertex, "VERTEX");

    //FRAGMENT SHADERS
    fragment= glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragment_code_ptr, NULL);
    glCompileShader(fragment);
    shader_check_compile_error(fragment, "FRAGMENT");
    //link shaders
    //shader program
    programID = glCreateProgram();
    glAttachShader(programID, vertex);
    glAttachShader(programID, fragment);
    glLinkProgram(programID);
    shader_check_compile_error(programID, "PROGRAM");

    //delete shaders after linking, they are no longer needed
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    return programID;
}


void shader_use(u32 shaderID) {
    glUseProgram(shaderID);
}

void shader_check_compile_error(u32 shaderID, const char* type) {
    int success;
    char infoLog[1024];

    if(strcmp(type, "PROGRAM") != 0){
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(shaderID, 1024, NULL, infoLog);
            printf("ERROR::SHADER_COMPILATION_ERROR of type %s \n", type);
            printf("%s\n-- --------------------------------------------------- --\n", infoLog);
        }
    } else {
        glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(shaderID, 1024, NULL, infoLog);
            printf("ERROR::SHADER_LINKING_ERROR of type %s \n", type);
            printf("%s\n-- --------------------------------------------------- --\n", infoLog);
        }
    }
}


void shader_set_mat4(u32 shaderID, const char* name, const mat4 mat) {
    glUniformMatrix4fv(glGetUniformLocation(shaderID, name), 1, GL_FALSE, mat.data);
}
