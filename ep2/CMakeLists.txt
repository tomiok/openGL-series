cmake_minimum_required(VERSION 3.20)
project(ep2)

set(CMAKE_CXX_STANDARD 20)

add_executable(ep2 main.cpp glad.c)
target_include_directories(ep2 PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies

)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(ep2 glfw OpenGL::GL ${CMAKE_DL_LIBS})
