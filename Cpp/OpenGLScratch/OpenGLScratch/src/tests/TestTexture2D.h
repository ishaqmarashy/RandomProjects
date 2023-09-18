#pragma once
#include "Test.h"
#include "Texture.h"
#include "VertexBufferLayout.h"
#include <glm/gtc/matrix_transform.hpp>
#include <imgui.h>
#include <memory>
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
		Renderer render;
		std::unique_ptr <VertexArray> va;
		std::unique_ptr <VertexBuffer> vb;
		std::unique_ptr <IndexBuffer> ib;
		std::unique_ptr <VertexBufferLayout> layout;
		std::unique_ptr <Texture> texture;
		std::unique_ptr <Shader> shader;
		glm::vec3 translationA;
		glm::vec3 translationB;
		glm::mat4 proj;
		glm::mat4 view;
		glm::vec4 m_ClearColorA;
		glm::vec4 m_ClearColorB;
	};
}
