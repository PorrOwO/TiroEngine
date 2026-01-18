#include "shader/shader.h"
#include <stdio.h>

#define GL_GLEXT_PROTOTYPES
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glext.h>

#include "common/defines.h"
#include "math/linalg.h"
#include "math/math.h"

void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, f64 xpos, f64 ypos);
void scroll_callback(GLFWwindow* window, f64 xoffset, f64 yoffset);

float vertices[] = {
    // positions         // colors
    0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
    0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
};

vec3 cameraPos   = (vec3){{0.0f, 0.0f,  3.0f}};
vec3 cameraFront = (vec3){{0.0f, 0.0f, -1.0f}};
vec3 cameraUp    = (vec3){{0.0f, 1.0f,  0.0f}};

int firstMouse = 1;
float yaw   = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
float pitch =  0.0f;
float lastX =  800.0f / 2.0;
float lastY =  600.0 / 2.0;
float fov   =  45.0f;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

int main()
{
    if (!glfwInit()) {
        printf("ERROR: GLFW failed to initialize\n");
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "TIRO", NULL, NULL);
    if(!window) {
        printf("ERROR: GLFW window creation failed\n");
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    u32 shader_id = shader_new("../src/content/shaders/vertex.glsl", "../src/content/shaders/fragment.glsl");
    u32 VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    while(!glfwWindowShouldClose(window)) {
        // per-frame time logic
        f32 current_frame = (f32)glfwGetTime();
        deltaTime = current_frame - lastFrame;
        lastFrame = current_frame;
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.7f, 0.1f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // activate shader
        shader_use(shader_id);
        
        // projection matrix
        mat4 projection =  mat4_perspective(radians(fov), (f32)WINDOW_WIDTH / (f32)WINDOW_HEIGHT, 0.1f, 100.0f);
        shader_set_mat4(shader_id, "projection", projection);
        // camera view transforms
        mat4 view = mat4_look_at(cameraPos, vec3_sum(cameraPos, cameraFront), cameraUp);
        shader_set_mat4(shader_id, "view", view);
        // model matrix (identity for now - no transformation on the triangle)
        mat4 model = mat4_identity();
        shader_set_mat4(shader_id, "model", model);
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, 1);

    f32 cameraSpeed = (f32)(2.5 * deltaTime);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos = vec3_sum(cameraPos, vec3_mul_scalar(cameraFront, cameraSpeed));
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos = vec3_sub(cameraPos, vec3_mul_scalar(cameraFront, cameraSpeed));
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos = vec3_sub(cameraPos, vec3_mul_scalar(vec3_normalized(vec3_cross_prod(cameraFront, cameraUp)), cameraSpeed));
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos = vec3_sum(cameraPos, vec3_mul_scalar(vec3_normalized(vec3_cross_prod(cameraFront, cameraUp)), cameraSpeed));
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, f64 xposIn, f64 yposIn)
{
    f32 xpos = (f32)(xposIn);
    f32 ypos = (f32)(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = 0;
    }

    f32 xoffset = xpos - lastX;
    f32 yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f; // change this value to your liking
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    vec3 front;
    front.x = cos(radians(yaw)) * cos(radians(pitch));
    front.y = sin(radians(pitch));
    front.z = sin(radians(yaw)) * cos(radians(pitch));
    cameraFront = vec3_normalized(front);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, f64 xoffset, f64 yoffset)
{
    fov -= (f32)yoffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;
}
