#ifndef EBO_CLASS_HPP
#define EBO_CLASS_HPP

#include <GL/glew.h>

class EBO
{
    public:
        GLuint id;
        EBO(GLuint* indices, GLsizeiptr size);

        void Bind();
        void Unbind();
        void Delete();
};

#endif