//#include <glad/glad.h> 
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
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
		-0.5f,   0.5f
	};
	unsigned int indices[] = {
	0,1,2,
	2,3,0
	};

	VertexArray va;
	VertexBuffer vb(positions, 4*2 * sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(3);
	va.AddBuffer(vb,layout);
	IndexBuffer ib(indices,6);	

	unsigned int shaderProgram=ParseShader("basic.shader");
	glUseProgram(shaderProgram);

	//get u_colors location assert its been received then set its value
	int u_colorLocation = glGetUniformLocation(shaderProgram, "u_color");
	ASSERT(u_colorLocation != -1);
	float r, g, b, a;
	while (!glfwWindowShouldClose(window)) {
		r = std::cos(glfwGetTime()) * 1.0f;
		g = std::sin(glfwGetTime()) * 1.0f;
		b = std::tan(glfwGetTime()) * 1.0f;
		a = std::tanh(glfwGetTime()) * 1.0f;
		glUniform4f(u_colorLocation, r,g,b,a);

		glClear(GL_COLOR_BUFFER_BIT);
		//draw triangles from an array starting from index 0 ending at index3
		//opengl only knows what to draw cause we bound the buffer on line 37
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		GLCall(glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, nullptr));

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}