//
// Created by tomasito on 8/3/26.
//
#ifndef EP3_EBO_VAO_H
#define EP3_EBO_VAO_H
#include "glad/glad.h"
#include "VBO.h"


class VAO {
    public:
    unsigned int ID;
    VAO();

    void Link(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
    void Bind();
    void Unbind();
    void Delete();
};

#endif //EP3_EBO_VAO_H
