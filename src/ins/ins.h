#ifndef INS_H
#define INS_H
// Standard Libraries

#include <iostream>

// Public Libraries 

#include "../include/glad/glad.h"

#include "../include/GLFW/glfw3.h"
#include "../include/GLFW/glfw3native.h"

// Source header files
#include "../text_editor.h"
#include "../keyboard_input.h"
#include "../shader_manager.h"
#include "../render.h"
#include "../text_memory.h"

// TODO: Figure out where to place these below variables

static float vertices[] = {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 
     0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,   
    -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
};

static unsigned int indices[] = {  
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
#endif
