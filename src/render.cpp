#include "render.h"

void Render::TextRenderInit()
{
    TextShader.CreateShader("W:/TextEditor/res/shaders/shader.vs", "W:/TextEditor/res/shaders/shader.fs");
    
    unsigned int VBO, EBO;

    glGenVertexArrays(1, &TextVAO);  

    glGenBuffers(1, &VBO);

    glBindVertexArray(TextVAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  
}
