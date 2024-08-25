#ifndef RENDER_H
#define RENDER_H

#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include "../include/GLFW/glfw3native.h"

#include "shader_manager.h"

static float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};  

class Render
{
public:
    ShaderManager TextShader;
    ShaderManager UIShader;
    unsigned int TextVAO;
    unsigned int UIVAO;

public:
    void TextRenderInit();
};



#endif