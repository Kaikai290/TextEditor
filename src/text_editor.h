#ifndef TEXT_EDITOR
#define TEXT_EDITOR

#include "render.h"
#include "text_memory.h"

class TextEditor {
public:
  class Render Renderer;
  class TextMemory Memory;
  GLFWwindow *Window;
public:
  int Init();
};

#endif
