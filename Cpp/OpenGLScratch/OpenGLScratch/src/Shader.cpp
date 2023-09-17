#include "Shader.h"
#include "Renderer.h"


Shader::Shader(const std::string& filepath)
	:m_FilePath(filepath), m_RendererID(0)
{
	ShaderProgramSource source = ParseShader(filepath);
	m_RendererID = CreateShader(source.VertexSource,source.FragmentSource);
}
Shader::~Shader()
{
	glDeleteProgram(m_RendererID);
}

ShaderProgramSource Shader::ParseShader(const std::string& filepath)
{
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
	return ShaderProgramSource(ss[0].str(), ss[1].str());
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source) {
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
		auto* message = (char*) alloca(length* sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile\n";
		glDeleteShader(id);
		return 0;
	}
	return id;
}

unsigned int Shader::CreateShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) {
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

void Shader::Bind() const
{
	glUseProgram(m_RendererID);
}

void Shader::Unbind() const
{
	glUseProgram(0);
}

void Shader::SetUniform1i(const std::string& name, int value)
{
	glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetUniform1f(const std::string& name, float value)
{
	glUniform1f(GetUniformLocation(name), value);
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
}

void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& matrix)
{
	GLCall(glUniformMatrix4fv(GetUniformLocation(name),1,GL_FALSE,&matrix[0][0]));
}

int Shader::GetUniformLocation(const std::string& name)
{
	if (m_UniformLocationCache.contains(name))
		return m_UniformLocationCache[name];

	int location = glGetUniformLocation(m_RendererID, name.c_str());
	if (location == -1) std::cout << " Warning: uniform '" << name << "' doesnt exist!\n";
	return location;
}

