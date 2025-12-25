#include <glbinding/gl/gl.h>
#include <glbinding/glbinding.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Optional: Set OpenGL version hints (for modern OpenGL core profile)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window (800x600, titled "GLFW Window")
    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello GLFW Window", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's OpenGL context current
    glfwMakeContextCurrent(window);

    // Initialize glbinding
    glbinding::initialize([](const char* name) { return glfwGetProcAddress(name); });

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Poll for events (keyboard, mouse, etc.)
        glfwPollEvents();

        // Clear the screen with a cornflower blue color
        glClearColor(0.39f, 0.58f, 0.93f, 1.0f);  // RGBA
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers (show what we've drawn)
        glfwSwapBuffers(window);
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}