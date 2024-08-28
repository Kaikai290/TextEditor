#ifndef TEXT_MEMORY_H
#define TEXT_MEMORY_H


#include "../include/glad/glad.h"
#include "../include/GLFW/glfw3.h"
#include "../include/GLFW/glfw3native.h"

#include <iostream>

void character_callback(GLFWwindow* window, unsigned int codepoint);

class TextMemory
{
public:
    std::string Text;
public:
    void AddChar(char Letter);
};

#endif