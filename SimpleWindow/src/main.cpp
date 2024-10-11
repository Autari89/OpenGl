#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
    // Setup the glfw context
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Setup GLFW window properties
    // OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Remove backward compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Allow forward compatibility
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create the window
    GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Main Window", nullptr, nullptr);

    if (!mainWindow)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    // Get Frame buffer size and set current context
    int buffferWidth;
    int bufferHeight;

    glfwGetFramebufferSize(mainWindow, &buffferWidth, &bufferHeight);
    glfwMakeContextCurrent(mainWindow);

    glewExperimental = GL_TRUE;
    
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Error initializing GLEW" << std::endl;
        // Cleanup and return
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return -1;
    }

    // Set the Viewport to OpenGl
    glViewport(0, 0, buffferWidth, bufferHeight);

    // Create main loop event
    while (!glfwWindowShouldClose(mainWindow))
    {
        // Create a handle to user event 
        glfwPollEvents();

        // Clear the window to be completely RED and specify the color mask
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);  
        
        // Swap the current frame with the one which was just modified
        glfwSwapBuffers(mainWindow);
    }
    

    return 0;
}