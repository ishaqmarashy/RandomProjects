//#include <glad/glad.h> 
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#define HEIGHT 640
#define WIDTH 480


int main() {
	GLFWwindow* window;
	if (!glfwInit()) return -1;
	//specify version and profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(WIDTH, HEIGHT,"OpenGL From Scratch!", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	if (!glewInit() == GLEW_OK) {
		std::cout << "Error\n";
		return -1;
	}
	float positions[] = {
		-0.5f, -0.5f,
		0.5f,  -0.5f,
		0.5f,   0.5f,
		-0.5f,   0.5f,
	};
	unsigned int indices[] = {
	0,1,2,
	2,3,0
	};

	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	/*
	//give unsigned int to open gl to get id
	unsigned int buffer;
	//1 is for the number of buffers we want to generate
	glGenBuffers(1, &buffer);
	//select buffer  and specify what kind of data it is
	//by using array buffer we say that it is an array of data
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	//specify size of buffer - the data of the buffer- how it will be used and what its used for
	glBufferData(GL_ARRAY_BUFFER, 2*6 * sizeof(float),positions,GL_STATIC_DRAW);
	//glBindBuffer(GL_ARRAY_BUFFER, 0); //0 unbinds all buffers
	glEnableVertexAttribArray(0);
	//index specify what vertexarray is bound to the buffer 0 is current (vao) - size per vertex - type - normalize 0-1?? - how much to move forward to get to next attribute- pointer to starting coordinate you may need to cast
	//this binds the buffer with the vao
	glVertexAttribPointer(0, 2,GL_FLOAT, GL_FALSE, sizeof(float) * 2, (const void*)0);
	glEnableVertexAttribArray(0);
	*/

	VertexBuffer vb(positions, 4*2 * sizeof(float));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (const void*)0);
	IndexBuffer ib(indices,6);

	unsigned int shaderProgram=ParseShader("basic.shader");
	glUseProgram(shaderProgram);

	//get u_colors location assert its been recieved then set its value
	int u_colorLocation = glGetUniformLocation(shaderProgram, "u_color");
	ASSERT(u_colorLocation != -1);
	float r, g, b, a;
	r = std::cos(glfwGetTime()) * 1.0f;
	while (!glfwWindowShouldClose(window)) {
		g = std::sin(glfwGetTime()) * 1.0f;
		b = std::tan(glfwGetTime()) * 1.0f;
		a = std::tanh(glfwGetTime()) * 1.0f;
		glUniform4f(u_colorLocation, r,g,b,a);
		ib.Bind();
		vb.Bind();
		glClear(GL_COLOR_BUFFER_BIT);
		//draw triangles from an array starting from index 0 ending at index3
		//opengl only knows what to draw cause we bound the buffer on line 37
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}