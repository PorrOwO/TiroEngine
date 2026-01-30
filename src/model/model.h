#pragma once 
#include "common/files.h"
#include "common/defines.h"

typedef struct {
    f32_darray verts;    
} Model;

// Create a new model struct give a .obj file
IOStatus model_from_obj(const char* file_path, Model* m);
