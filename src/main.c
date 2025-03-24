#include <GLFW/glfw3.h>
#include <GL/gl.h>

int main(void)
{
    // Initialize GLFW
    if (!glfwInit())
        return -1;

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Magnus Engine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // OpenGL setup
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Set background color

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw a simple triangle (you can replace this with more complex code later)
        glBegin(GL_TRIANGLES); // Start drawing a triangle
        glColor3f(1.0f, 0.0f, 0.0f); // Set the color to red
        glVertex2f(0.0f, 0.5f); // Top vertex
        glColor3f(0.0f, 1.0f, 0.0f); // Set the color to green
        glVertex2f(-0.5f, -0.5f); // Bottom-left vertex
        glColor3f(0.0f, 0.0f, 1.0f); // Set the color to blue
        glVertex2f(0.5f, -0.5f); // Bottom-right vertex
        glEnd(); // End drawing

        // Swap buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
