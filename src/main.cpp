#include <iostream>

#include "../include/glad/glad.h"

#include "../include/GLFW/glfw3.h"
#include "../include/GLFW/glfw3native.h"

#include "text_editor.h"
#include "render.h"

void character_callback(GLFWwindow *window, unsigned int codepoint);

struct Globals {
  class Render Renderer;
  GLFWwindow *Window;
  class TextMemory TextMemory;
};

void mainLoop(TextEditor *TextEditor);
void character_callback(GLFWwindow *window, unsigned int codepoint);

int main() {
  TextEditor TextEditor;
  TextEditor.Init(); 
  TextEditor.Renderer.TextRenderInit();
  TextEditor.Renderer.FontLoader("W:/TextEditor/res/fonts/enter_command0.png");
  /* Turn on keyboard CallBack */

  glfwSetCharCallback(TextEditor.Window, character_callback);

  /* Loop until the user closes the window */
  mainLoop(&TextEditor);

  glfwTerminate();
  return 0;
}

void mainLoop(TextEditor *TextEditor)
{
  while (!glfwWindowShouldClose(TextEditor->Window)) {
    /* Render here */
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    TextEditor->Renderer.TextShader.UseShader();
    glBindTexture(GL_TEXTURE_2D, TextEditor->Renderer.Font.Texture);
    glBindVertexArray(TextEditor->Renderer.TextVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    /* Swap front and back buffers */
    glfwSwapBuffers(TextEditor->Window);

    /* Poll for and process events */
    glfwPollEvents();
  }
}

void character_callback(GLFWwindow *window, unsigned int codepoint) {

  char CurrentLetter = codepoint;
//  Global.TextMemory.AddChar(CurrentLetter);
//  std::cout << Global.TextMemory.Text << std::endl;
}
