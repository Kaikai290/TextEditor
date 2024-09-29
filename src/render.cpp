#include <cwchar>
#include <iostream>

#include "render.h"
#include "ins/ins.h"

void Render::TextRenderInit() {
  int nrAttributes;
  glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
  std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes
            << std::endl;

  TextShader.CreateShader("W:/TextEditor/res/shaders/shader.vs",
                          "W:/TextEditor/res/shaders/shader.fs");

  unsigned int VBO, EBO;

  glGenVertexArrays(1, &TextVAO);

  glGenBuffers(1, &VBO);

  glGenBuffers(1, &EBO);
  

  glBindVertexArray(TextVAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
}

void Render::FontLoader(const char *FilePath)
{
  SpriteManager CurrentFont(FilePath);
  Font = CurrentFont; 
}
