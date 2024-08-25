#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include<iostream>
#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include "../include/GLFW/glfw3native.h"

static const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}";

static const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 1.0f, 0.2f, 1.0f);\n"
    "}";


class ShaderManager
{
public:
    unsigned int shaderProgram;
public:
    //ShaderManager();

    void CreateShader();
};




#endif