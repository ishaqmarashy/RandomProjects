#include "shader.h"

struct ShaderProgramSource {
	int vs;
	int fx;
};
enum class ShaderType {
	NONE = -1, VERTEX = 0, FRAGMENT = 1
};

static unsigned int CompileShader(unsigned int type, const std::string& source) {
	unsigned int id = glCreateShader(type);
	const char* srcPtr = &source[0];
	//first is the shader -count of source codes- source code--how far should it read
	glShaderSource(id, 1, &srcPtr, nullptr);
	glCompileShader(id);
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*) alloca(length* sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile\n";
		glDeleteShader(id);
	}

	return id;
}

static unsigned int CreateShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) {
	unsigned int program=glCreateProgram();

	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

	glAttachShader(program,vs);
	glAttachShader(program, fs);

	glLinkProgram(program);
	glValidateProgram(program);

	glDetachShader(program,vs);
	glDetachShader(program, fs);

	glDeleteShader(fs);
	glDeleteShader(vs);

	return program;
}

 unsigned int ParseShader(const std::string& filepath) {
	std::ifstream stream(filepath);
	std::string line;
	std::stringstream ss[2];
	ShaderType type;

	while (getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else {
			ss[(int)type] << line << '\n';
		}

	}
	return CreateShader(ss[0].str(), ss[1].str());
}