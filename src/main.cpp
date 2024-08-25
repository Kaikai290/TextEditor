#include<iostream>
#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include "../include/GLFW/glfw3native.h"

#include "KeyboardInput.h"
#include "ShaderManager.h"

void mainLoop(GLFWwindow* window, unsigned int shaderProgram, unsigned int VAO);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

static float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};  

int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    /* Turn on keyboard CallBack */

    glfwSetKeyCallback(window, key_callback);

    /*Gen Shaders*/
    
    ShaderManager Shader;
    Shader.CreateShader();


    /*set up VBO/VAO*/

    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);  
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    // 0. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // 1. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  
    // 2. use our shader program when we want to render an object
    glUseProgram(Shader.shaderProgram);
    // 3. now draw the object 

    /* Loop until the user closes the window */
    mainLoop(window, Shader.shaderProgram, VAO);

    glfwTerminate();
    return 0;
}

void mainLoop(GLFWwindow* window, unsigned int shaderProgram, unsigned int VAO)
{
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // Save the states of the keys to allow for multiple button presses
    // Forexample shift+letter for capital ect
    // could look into modifier key flags the int mods
    if (mods == 4)
        {
            std::cout <<  "caps" << std::endl;
        }
    const char CurrentKey = key;
    std::cout <<  CurrentKey << " and " << action << " and " << mods << std::endl;
}