#include "shader_manager.h"

void ShaderManager::CreateShader(std::string VertexFilePath, std::string FragmentFilePath)
{
    unsigned int VertexShader;
    if(!(VertexShader = glCreateShader(GL_VERTEX_SHADER)))
    {
        std::cout << "Failed to create vertex shader object" <<std::endl;
    }
    std::string VertexShaderFile = LoadShaderFromFile(VertexFilePath);
    const char *VertexShaderFilePointer = VertexShaderFile.c_str();

    glShaderSource(VertexShader, 1, &VertexShaderFilePointer, NULL);
    glCompileShader(VertexShader);
    checkCompileErrors(VertexShader, "VERTEX");
  

    unsigned int FragmentShader;
    if(!(FragmentShader = glCreateShader(GL_FRAGMENT_SHADER)))
    {
        std::cout << "Failed to create fragment shader object" <<std::endl;
    }

    std::string FragmentShaderFile = LoadShaderFromFile(FragmentFilePath);
    const char *FragmentShaderFilePointer = FragmentShaderFile.c_str();

    glShaderSource(FragmentShader, 1, &FragmentShaderFilePointer, NULL);
    glCompileShader(FragmentShader);
    checkCompileErrors(FragmentShader, "FRAGMENT");

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, VertexShader);
    glAttachShader(shaderProgram, FragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(VertexShader);
    glDeleteShader(FragmentShader);
}
void ShaderManager::UseShader()
{
    glUseProgram(shaderProgram);
}

std::string ShaderManager::LoadShaderFromFile(std::string FilePath)
{
    std::ifstream ShaderFile(FilePath);

    if(!ShaderFile.is_open())
    {
        std::cout << "Failed to open Shader File at address: " << FilePath << std::endl;
    }

    std::stringstream Shader;

    Shader << ShaderFile.rdbuf();
    std::string StringShader = Shader.str();

    ShaderFile.close();

    return StringShader;
}

void ShaderManager::checkCompileErrors(unsigned int object, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(object, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(object, 1024, NULL, infoLog);
            std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
                << infoLog << "\n -- --------------------------------------------------- -- "
                << std::endl;
        }
    }
    else
    {
        glGetProgramiv(object, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(object, 1024, NULL, infoLog);
            std::cout << "| ERROR::Shader: Link-time error: Type: " << type << "\n"
                << infoLog << "\n -- --------------------------------------------------- -- "
                << std::endl;
        }
    }
}

