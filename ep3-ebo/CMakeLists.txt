cmake_minimum_required(VERSION 3.20)
project(ep3-ebo)

set(CMAKE_CXX_STANDARD 20)

add_executable(ep3-ebo main.cpp glad.c
        shaders.h
        shaders.cpp
        EBO.h
        VBO.cpp
        VAO.h
        VAO.cpp
        VBO.h
        EBO.cpp
        stb_image.h
        stb.cpp)
target_include_directories(ep3-ebo PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies

)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(ep3-ebo glfw OpenGL::GL ${CMAKE_DL_LIBS})
