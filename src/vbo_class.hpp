#ifndef VBO_CLASS_HPP
#define VBO_CLASS_HPP

#include <GL/glew.h>

class VBO
{
    public:
        GLuint id;
        VBO(GLfloat* vertices, GLsizeiptr size);

        void Bind();
        void Unbind();
        void Delete();
};

#endif