#include "Renderer.h"

void glClearErrors(){
	while (glGetError() != GL_NO_ERROR);
}

bool glLogCall(const char* function,const char* file,int line) {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGL Error] (" << error << ") "<< function << " " << file<<":"<<line<<'\n';
		return false;
	}
	return true;
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{

	shader.Bind();
	va.Bind();
	ib.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

}
