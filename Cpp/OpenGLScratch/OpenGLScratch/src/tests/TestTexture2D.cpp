#include "TestTexture2D.h"

namespace test {
	TestTexture::TestTexture() :
		proj(glm::ortho(0.0f, WIDTH * 1.0f, 0.0f, HEIGHT * 1.0f, -1.0f, 1.0f)),
		view(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0))),
		translationA(glm::vec3(200, 200, 0)),
		translationB(glm::vec3(400, 200, 0)),
		m_ClearColorA{ 1.0f,1.0f,1.0f,1.0f },
		m_ClearColorB{ 1.0f,1.0f,1.0f,1.0f }
	{
		float positions[] = {
					-50.0f, -50.0f, 0.0f,0.0f,
					50.0f, -50.0f, 1.0f,0.0f,
					50.0f,  50.0f, 1.0f,1.0f,
					-50.0f,  50.0f, 0.0f,1.0f };
		unsigned int indices[] = { 0,1,2,2,3,0 };
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		va = std::make_unique<VertexArray>();
		va->Bind();
		vb = std::make_unique<VertexBuffer>(positions, 4 * 4 * sizeof(float));
		vb->Bind();
		ib = std::make_unique<IndexBuffer>(indices, 6);
		ib->Bind();
		layout = std::make_unique<VertexBufferLayout>();
		layout->Push<float>(2);
		layout->Push<float>(2);
		va->AddBuffer(*vb, *layout);
		shader = std::make_unique<Shader>("res/shaders/basic.shader");
		shader->Bind();
		texture = std::make_unique<Texture>("res/textures/T1.png");
		texture->Bind();
		shader->SetUniform1i("u_Texture", 0);
	}
	TestTexture::~TestTexture()
	{
		texture->Unbind();
		shader->Unbind();
		ib->Unbind();
		vb->Unbind();
		va->Unbind();
	}
	void TestTexture::OnUpdate(float deltaTime)
	{
		va->Bind();
		vb->Bind();
		ib->Bind();
		texture->Bind();
		shader->Bind();
	}
	void TestTexture::OnRender()
	{
		{
			shader->SetUniform4f("u_Color", m_ClearColorA);
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
			glm::mat4 mvp = proj * view * model;
			shader->SetUniformMat4f("u_MVP", mvp);
			render.Draw(*va, *ib, *shader);
		}
		{
			shader->SetUniform4f("u_Color", m_ClearColorB);
			glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
			glm::mat4 mvp = proj * view * model;
			shader->SetUniformMat4f("u_MVP", mvp);
			render.Draw(*va, *ib, *shader);
		}
	}
	void TestTexture::OnImGuiRender()
	{
		ImGui::Text("Texture A");
		ImGui::SliderFloat3("Texture A Translation", &translationA.x, 0.0f, WIDTH * 1.0f);
		ImGui::SliderFloat4("Texture A Color", &m_ClearColorA[0], 0.0f, 255.0f);
		ImGui::Text("Texture B");
		ImGui::SliderFloat3("Texture B Translation", &translationB.x, 0.0f, WIDTH * 1.0f);
		ImGui::SliderFloat4("Texture B Color", &m_ClearColorB[0], 0.0f, 255.0f);
	}
}