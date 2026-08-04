//
// Created by tomasito on 8/2/26.
//

#ifndef EP3_EBO_SHADERS_H
#define EP3_EBO_SHADERS_H


#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

std::string get_file_contents(const char* filename);

class Shader
{
public:
    // Reference ID of the Shader Program
    GLuint ID;
    // Constructor that build the Shader Program from 2 different shaders
    Shader(const char* vertexFile, const char* fragmentFile);

    // Activates the Shader Program
    void Activate();
    // Deletes the Shader Program
    void Delete();
};
#endif
