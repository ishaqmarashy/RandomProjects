#include "TestTexture2D.h"

namespace test {
	TestTexture::TestTexture():
		vb(positions, 4 * 4 * sizeof(float)),ib(indices, 6),n_texture("u_Texture"),
		texture("rg"), shader("res/shaders/basic.shader"), translation(200, 200, 0),
		positions{ -50.0f, -50.0f, 0.0f,0.0f,50.0f, -50.0f, 1.0f,0.0f,  50.0f,  50.0f, 1.0f,1.0f, -50.0f,  50.0f, 0.0f,1.0f },
		indices{ 0,1,2,2,3,0 }, n_color("u_Color"), n_mvp("u_MVP"), m_ClearColor{ 0.2f,0.3f,0.8f,1.0f }
	{
		proj = glm::ortho(0.0f, WIDTH * 1.0f, 0.0f, HEIGHT * 1.0f, -1.0f, 1.0f);
		view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
		layout.Push<float>(2);
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);
		va.Bind();
		vb.Bind();
		ib.Bind();
		texture.Bind();
		shader.Bind();
	}
	TestTexture::~TestTexture()
	{
		shader.Unbind();
		va.Unbind();
		vb.Unbind();
		ib.Unbind();
	}
	void TestTexture::OnUpdate(float deltaTime)
	{
	}
	void TestTexture::OnRender()
	{
		va.Bind();
		vb.Bind();
		ib.Bind();
		texture.Bind();
		shader.Bind();
		shader.SetUniform1i(n_texture, 0);
		shader.SetUniform4f(n_color, m_ClearColor[0], m_ClearColor[1], m_ClearColor[2], m_ClearColor[3]);
		glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
		glm::mat4 mvp = proj * view * model;
		shader.SetUniformMat4f(n_mvp, mvp);
		render.Draw(va, ib, shader);
	}
	void TestTexture::OnImGuiRender()
	{
		va.Bind();
		vb.Bind();
		ib.Bind();
		texture.Bind();
		shader.Bind();
		ImGui::SliderFloat3("Texture Translation", &translation.x, 0.0f, WIDTH * 1.0f);
		ImGui::SliderFloat4("Texture Color", &m_ClearColor[0], 0.0f, 1.0f);
		render.Draw(va, ib, shader);
	}
}