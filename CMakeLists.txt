cmake_minimum_required(VERSION 3.5.0)

project(TextEditor VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenGL REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(TextEditor src/main.cpp src/glad.c)

target_link_libraries(TextEditor ${CMAKE_SOURCE_DIR}/lib/glfw3dll.lib ${OPENGL_LIBRARIES})