//#include <glad/glad.h> 
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#define HEIGHT 540
#define WIDTH 960


int main() {
	GLFWwindow* window;
	if (!glfwInit()) return -1;
	//specify version and profile
	const char* glsl_version = "#version 130";
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
	//------------imgui------------------
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
	//-----------------------------------
	float positions[] = {
		-50.0f, -50.0f, 0.0f,0.0f,
		 50.0f, -50.0f, 1.0f,0.0f,
		 50.0f,  50.0f, 1.0f,1.0f,
		-50.0f,  50.0f, 0.0f,1.0f
	};
	unsigned int indices[] = {
	0,1,2,
	2,3,0
	};
	//-----------------------------------
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	VertexArray va;
	VertexBuffer vb(positions,4*4*sizeof(float));
	VertexBufferLayout layout;
	layout.Push<float>(2);
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);
	IndexBuffer ib(indices, 6);
	//-----------------------------------
	glm::mat4 proj = glm::ortho(0.0f,WIDTH*1.0f,0.0f, HEIGHT*1.0f, -1.0f, 1.0f);
	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
	//-----------------------------------
	Shader shader("res/shaders/basic.shader");
	Texture texture("res/textures/T1.png");
	shader.Bind();
	shader.SetUniform1i("u_Texture", 0);
	//----unbinds-------------------------
	//------------------------------------
	//get u_colors location assert its been received then set its value
	Renderer render;
	std::string color = "u_Color";
	float r, g, b, a=1.0f;
	glm::vec3 translationA = glm::vec3(200, 200, 0);
	glm::vec3 translationB = glm::vec3(400, 200, 0);
	bool show_another_window = true;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	//------------------------------------
	while (!glfwWindowShouldClose(window)) {
		va.Bind();
		vb.Bind();
		ib.Bind();
		texture.Bind();
		glClear(GL_COLOR_BUFFER_BIT);
		glfwPollEvents();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		//--------------------------------
		r = std::cos(glfwGetTime()) * 1.0f;
		g = std::sin(glfwGetTime()) * 1.0f;
		b = std::tan(glfwGetTime()) * 1.0f;
		shader.SetUniform4f(color, r, g, b, a);
		//--------------------------------
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
			glm::mat4 mvp = proj * view * model;
			shader.SetUniformMat4f("u_MVP", mvp);
			render.Draw(va, ib, shader);
		}
		//--------------------------------
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
			glm::mat4 mvp = proj * view * model;
			shader.SetUniformMat4f("u_MVP", mvp);
			render.Draw(va, ib, shader);
		}
		//---------------------------------
		ImGui::Begin("Main Window", &show_another_window);
		{
			static float f = 0.0f;
			ImGui::SliderFloat3("Translation A", &translationA.x, 0.0f, WIDTH * 1.0f);
			ImGui::SliderFloat3("Translation B", &translationB.x, 0.0f, WIDTH * 1.0f);
			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
			ImGui::End();
		}
		//---------------------------------

		//draw triangles from an array starting from index 0 ending at index3
		//opengl only knows what to draw cause we bound the buffer on line 37
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		ImGui::Render();
		int display_w, display_h;
		glfwGetFramebufferSize(window, &display_w, &display_h);
		glViewport(0, 0, display_w, display_h);
		glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//-----------------------------------
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}