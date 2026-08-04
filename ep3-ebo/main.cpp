#include <cmath>
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <EBO.h>
#include <VBO.h>
#include <VAO.h>
#include <shaders.h>

// Vertex Shader source code
const char *vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
//Fragment Shader source code
const char *fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
        "}\n\0";

int main() {
    glfwInit();

    float vertices[] = {
        -0.5f, -0.5f , 0.0f, // Lower left corner
        0.5f, -0.5f  , 0.0f, // Lower right corner
        0.5f, 0.5f  , 0.0f, // Upper right
        -0.5f, 0.5f , 0.0f, // Upper left
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0,

    };

    //create window
    GLFWwindow *window = glfwCreateWindow(800, 720, "OpenGL ep 3 - EBOs", NULL, NULL);
    if (window == nullptr) {
        return -1;
    }
    // attach
    glfwMakeContextCurrent(window);

    //init openGL
    gladLoadGL();

    // what part of the screen is going to be used by openGL
    glViewport(0, 0, 800, 720);

    //shaders
    Shader shaderProgram("vertex.shader", "fragment.shader");

    // Generates Vertex Array Object and binds it
    VAO VAO1;
    VAO1.Bind();

    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1(vertices, sizeof(vertices));
    // Generates Element Buffer Object and links it to indices
    EBO EBO1(indices, sizeof(indices));

    // Links VBO to VAO
    VAO1.Link(VBO1, 0);
    // Unbind all to prevent accidentally modifying them
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    //glEnable(GL_PROGRAM_POINT_SIZE);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    //keep the window open until it closes
    while (!glfwWindowShouldClose(window)) {
        // Specify the color of the background
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        // Clean the back buffer and assign the new color to it
        glClear(GL_COLOR_BUFFER_BIT);
        // Tell OpenGL which Shader Program we want to use
        shaderProgram.Activate();
        // Bind the VAO so OpenGL knows to use it
        VAO1.Bind();
        // Draw primitives, number of indices, datatype of indices, index of indices
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
        // Swap the back buffer with the front buffer
        glfwSwapBuffers(window);
        // Take care of all GLFW events
        glfwPollEvents();
    }

    // destroy everything
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
