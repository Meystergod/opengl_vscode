#ifndef VAO_CLASS_HPP
#define VAO_CLASS_HPP

#include <GL/glew.h>
#include "vbo_class.hpp"

class VAO
{
    public:
        GLuint id;
        VAO();

        void Link(VBO VBO, GLuint layout, GLuint num_components, GLenum type, GLsizeiptr stride, void* offset);
        void Bind();
        void Unbind();
        void Delete();
};

#endif