//#include <glad/glad.h> 
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
#define HEIGHT 1200
#define WIDTH 1200


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
		-0.5f, -0.5f, 0.0f,0.0f,
		 0.5f, -0.5f, 1.0f,0.0f,
		 0.5f,  0.5f, 1.0f,1.0f,
		-0.5f,  0.5f, 0.0f,1.0f
	};
	unsigned int indices[] = {
	0,1,2,
	2,3,0
	};

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	VertexArray va;
	VertexBuffer vb(positions,4*4*sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);
	IndexBuffer ib(indices, 6);

	Shader shader("res/shaders/basic.shader");
	Texture texture("res/textures/T1.png");
	shader.SetUniform1i("u_Texture", 0);

	//get u_colors location assert its been received then set its value
	Renderer render;
	std::string color = "u_Color";
	float r, g, b, a;
	while (!glfwWindowShouldClose(window)) {
		r = std::cos(glfwGetTime()) * 1.0f;
		g = std::sin(glfwGetTime()) * 1.0f;
		b = std::tan(glfwGetTime()) * 1.0f;
		a = 1.0f;
		va.Bind();
		vb.Bind();
		ib.Bind();
		shader.SetUniform4f(color, r, g, b, a);
		texture.Bind();
		glClear(GL_COLOR_BUFFER_BIT);
		render.Draw(va, ib, shader);
		//draw triangles from an array starting from index 0 ending at index3
		//opengl only knows what to draw cause we bound the buffer on line 37
		//glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}