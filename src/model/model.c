#include "model.h"
#include "common/defines.h"
#include "common/files.h"
#include <stdio.h>
#include <stdlib.h>

IOStatus model_from_obj(const char* file_path, Model* m) {
    string_t file_content;
    IO_CHECK(file_read_all(&file_content, file_path));
    
    char* cursor = file_content.data;
    f32_darray vertices = {0};
    u32_darray faces = {0};

    while (*cursor) {
        if (*cursor == '\n' || *cursor == '\r' || *cursor == ' ') {
            cursor++;
            continue;
        }

        if (cursor[0] == 'v' && cursor[1] == ' ') {
            f32 x, y, z;
            sscanf(cursor, "v %f %f %f", &x, &y, &z); 
            
            da_append(vertices, x);
            da_append(vertices, y);
            da_append(vertices, z);
        }
        else if (cursor[0] == 'f' && cursor[1] == ' ') {
            cursor += 2;
            for (int i = 0; i < 3; i++) {
                char* end_ptr;
                long index = strtol(cursor, &end_ptr, 10);

                // OBJ is 1-based, OpenGL is 0-based
                da_append(faces, (int)(index - 1));

                // Skip over the slash stuff (textures/normals) to find the next number
                cursor = end_ptr;
                while (*cursor != ' ' && *cursor != '\n' && *cursor != '\0') {
                    cursor++;
                }
                // Skip whitespace to get to the start of the next vertex
                while (*cursor == ' ') {
                    cursor++;
                }
            }
        }
        
        while (*cursor && *cursor != '\n') {
            cursor++;
        }
    }
    
    for (size_t i = 0; i < faces.count; i++) {
        u32 index = faces.items[i];
        u32 base_index = index * 3;

        f32 x = vertices.items[base_index + 0];
        f32 y = vertices.items[base_index + 1];
        f32 z = vertices.items[base_index + 2];

        da_append(m->verts, x);
        da_append(m->verts, y);
        da_append(m->verts, z);
    }

    da_free(vertices);
    da_free(faces);
    free(file_content.data);
    return IO_SUCCESS;
}
