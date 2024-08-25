#ifndef SHADERMANAGER_H
#define SHADERMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include "../include/GLFW/glfw3native.h"

//TODO: Make a logging system for when the shaders mess up (glGetShaderInfoLog)

class ShaderManager
{
public:
    unsigned int shaderProgram;

public:
    //ShaderManager();
    void CreateShader(std::string VertexFilePath, std::string FragmentFilePath);
    void UseShader();
    std::string LoadShaderFromFile(std::string FilePath);
};




#endif