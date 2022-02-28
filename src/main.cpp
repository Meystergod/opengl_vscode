#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shader_class.hpp"
#include "ebo_class.hpp"
#include "vao_class.hpp"
#include "vbo_class.hpp"

using namespace std;

GLfloat vertices[] = 
{
    -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,    0.8f, 0.3f, 0.02f,
    0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,     0.8f, 0.3f, 0.02f,
    0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,  1.0f, 0.6f, 0.32f,
    -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, 0.9f, 0.45f, 0.17f,
    0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,  0.8f, 0.45f, 0.17f,
    0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f,     0.8f, 0.3f, 0.02f
};
GLuint indices[] = 
{
    0, 3, 5,
    3, 2, 4,
    5, 4, 1
};

int main(int argc, char** argv)
{
    GLsizei width, height;

    glfwInit();
	if (!glfwInit())
	{
		cout << "Could not initialize GLFW" << endl;
		return EXIT_FAILURE;
	}

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    GLFWwindow* window = glfwCreateWindow((GLsizei)800, (GLsizei)800, "Main Window", NULL, NULL);
	if (window == NULL)
	{
		cout << "Could not create the window" << endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		cout << "Could not initialize GLEW" << endl;
        glfwDestroyWindow(window);
        glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

    Shader shader_program("src/shaders/shader.vert", "src/shaders/shader.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    VAO1.Link(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    VAO1.Link(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shader_program.Activate();
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shader_program.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();
    return EXIT_SUCCESS;
}