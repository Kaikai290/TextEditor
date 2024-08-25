#include<iostream>
#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include "../include/GLFW/glfw3native.h"

#include "keyboard_input.h"
#include "shader_manager.h"
#include "render.h"

struct Globals
{
    Render Renderer;
    GLFWwindow* Window;
};


void mainLoop(Globals Global);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);



int main()
{
    Globals Global;
    

    /* Initialize the library */
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    Global.Window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!Global.Window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(Global.Window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    /* Turn on keyboard CallBack */

    glfwSetKeyCallback(Global.Window, key_callback);

    /*Gen Shaders*/
    
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

    
    Global.Renderer.TextRenderInit();



    /* Loop until the user closes the window */
    mainLoop(Global);

    glfwTerminate();
    return 0;
}

void mainLoop(Globals Global)
{
    while (!glfwWindowShouldClose(Global.Window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        Global.Renderer.TextShader.UseShader();
        glBindVertexArray(Global.Renderer.TextVAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(Global.Window);

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