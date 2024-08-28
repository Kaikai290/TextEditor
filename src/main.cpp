#include<iostream>
#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include "../include/GLFW/glfw3native.h"

#include "keyboard_input.h"
#include "shader_manager.h"
#include "render.h"
#include "text_memory.h"
#include "callback_function.h"

void character_callback(GLFWwindow* window, unsigned int codepoint);

struct Globals
{
    Render Renderer;
    GLFWwindow* Window;
    TextMemory TextMemory;
};


void mainLoop(Globals Global);
void character_callback(GLFWwindow* window, unsigned int codepoint);

static Globals Global;


int main()
{  

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

    glfwSetCharCallback(Global.Window, character_callback);


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

void character_callback(GLFWwindow* window, unsigned int codepoint)
{
    
    char CurrentLetter = codepoint;
    Global.TextMemory.AddChar(CurrentLetter);
    std::cout << Global.TextMemory.Text << std::endl;

}
