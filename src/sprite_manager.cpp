#include "sprite_manager.h"

#include <iostream>

SpriteManager::SpriteManager() {}

SpriteManager::SpriteManager(const char *FilePath) {
  glGenTextures(1, &Texture);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  unsigned char *Data;

  Data = stbi_load(FilePath, &Width, &Height, &nrChannel, 0);

  if (Data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 500, 500, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, Data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }
  else {
    std::cout << "Failed to Load Texture" << std::endl;
  }
  stbi_image_free(Data);
}
