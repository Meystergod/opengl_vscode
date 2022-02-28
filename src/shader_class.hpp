#ifndef SHADER_CLASS_HPP
#define SHADER_CLASS_HPP

#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <errno.h>

using namespace std;

string get_file_contents(const char* file_path);

class Shader
{
    public:
        GLuint program_id;
        Shader(const char* vertex_path, const char* fragment_path);

        void Activate();
        void Delete();
};

#endif