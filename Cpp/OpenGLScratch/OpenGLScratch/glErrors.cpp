#include "shader.h"

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