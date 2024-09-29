#include <iostream>

#include "ins/ins.h"
#include "text_editor.h"

int TextEditor::Init() {
  /* Initialize the library */
  if (!glfwInit()) {
    std::cout << "Failed to initialize GLFW" << std::endl;
    return -1;
  }
  Window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!Window) {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(Window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }
  return 0;
}
