//
// Created by tomasito on 8/4/26.
//

#ifndef EP3_EBO_VBO_H
#define EP3_EBO_VBO_H

#include "glad/glad.h"

class VBO {
public:
    unsigned int ID;

    VBO(GLfloat *vertices, GLsizeiptr size);

    void Bind();

    void Unbind();

    void Delete();
};

#endif //EP3_EBO_VBO_H
