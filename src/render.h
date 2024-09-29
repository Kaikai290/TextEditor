#ifndef RENDER_H
#define RENDER_H

#include "../include/glad/glad.h"

#include "../include/GLFW/glfw3.h"
#include "../include/GLFW/glfw3native.h"


#include "shader_manager.h"
#include "sprite_manager.h"

class Render {
public:
  ShaderManager TextShader;
  ShaderManager UIShader;
  unsigned int TextVAO;
  unsigned int UIVAO;
  SpriteManager Font;

public:
  void TextRenderInit();
  void FontLoader(const char *FilePath);
};

#endif
