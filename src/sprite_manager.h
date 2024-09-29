#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include "../include/glad/glad.h"

#include "../include/GLFW/glfw3.h"
#include "../include/GLFW/glfw3native.h"

#include "../include/stb_image/stb_image.h"

class SpriteManager
{
public:
  int Width;
  int Height;
  int nrChannel;
  unsigned int Texture;

public:
  SpriteManager();
  SpriteManager(const char *FilePath);
};

#endif 
