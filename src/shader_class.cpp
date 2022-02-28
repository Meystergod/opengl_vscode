#include "shader_class.hpp"

string get_file_contents(const char* file_path)
{
    ifstream in(file_path, ios::binary);
    if (in.is_open())
    {
        string contents;
        in.seekg(0, ios::end);
        contents.resize(in.tellg());
        in.seekg(0, ios::beg);
        in.read(&contents[0], contents.size());
        in.close();

        return(contents);
    }
    else
    {
        cout << "Could not open the files with shaders." << endl;
        throw(errno);
    }
}

Shader::Shader(const char* vertex_path, const char* fragment_path)
{
    string vertex_code = get_file_contents(vertex_path);
    string fragment_code = get_file_contents(fragment_path);

    const char* vertex_src = vertex_code.c_str();
    const char* fragment_src = fragment_code.c_str();

    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_src, NULL);
    glCompileShader(vertex_shader);

    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_src, NULL);
    glCompileShader(fragment_shader);

    program_id = glCreateProgram();
    glAttachShader(program_id, vertex_shader);
    glAttachShader(program_id, fragment_shader);
    glLinkProgram(program_id);

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

void Shader::Activate()
{
    glUseProgram(program_id);
}

void Shader::Delete()
{
    glDeleteProgram(program_id);
}