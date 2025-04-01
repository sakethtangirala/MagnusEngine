#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdio.h>
#include "camera/camera.h"

Camera camera;  // Declare Camera object

// Function to initialize the camera
void init_camera() {
    float startPos[3] = {0.0f, 0.0f, 3.0f};
    camera_init(&camera, startPos);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Magnus Engine", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);  // Enable vsync

    // Initialize the camera
    init_camera();

    // Set OpenGL options
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);  // Set background color

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Process input and update camera (you'll implement this in camera_process_keyboard and camera_process_mouse_movement)
        
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);

        // Create a 3D pyramid and render it (you'll need to replace this with actual 3D object rendering code)
        glBegin(GL_TRIANGLES);  // Start drawing a pyramid
        glColor3f(1.0f, 0.0f, 0.0f);  // Set the color to red
        glVertex3f(0.0f, 0.5f, 0.0f);  // Top vertex
        glColor3f(0.0f, 1.0f, 0.0f);  // Set the color to green
        glVertex3f(-0.5f, -0.5f, 0.5f);  // Bottom-left vertex
        glColor3f(0.0f, 0.0f, 1.0f);  // Set the color to blue
        glVertex3f(0.5f, -0.5f, 0.5f);  // Bottom-right vertex
        glEnd();  // End drawing

        // Swap buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
