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

    void Link(VBO& vbo, GLuint layout);
    void Bind();
    void Unbind();
    void Delete();
};

#endif //EP3_EBO_VAO_H
