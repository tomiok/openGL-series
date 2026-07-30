cmake_minimum_required(VERSION 3.20)
project(oglTutorial)

set(CMAKE_CXX_STANDARD 20)

add_executable(oglTutorial main.cpp glad.c)
target_include_directories(oglTutorial PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies

)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(oglTutorial glfw OpenGL::GL ${CMAKE_DL_LIBS})
