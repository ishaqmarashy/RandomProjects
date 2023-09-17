#pragma once
#include "Test.h"
#include "Texture.h"
#include "VertexBufferLayout.h"
#include <glm/gtc/matrix_transform.hpp>
#include <imgui.h>
#define HEIGHT 540
#define WIDTH 960

namespace test {

	class TestTexture : public Test
	{
	public:
		TestTexture();
		~TestTexture();

		void OnUpdate(float deltaTime);
		void OnRender();
		void OnImGuiRender();
	private:
		VertexArray va;
		VertexBuffer vb;
		IndexBuffer ib;
		Texture texture;
		Shader shader;
		Renderer render;
		VertexBufferLayout layout;
		std::string n_color;
		std::string n_mvp;
		std::string n_texture;
		glm::vec3 translation;
		glm::mat4 proj;
		glm::mat4 view;
		float positions[16];
		unsigned int indices[6];
		float m_ClearColor[4];
	};
}