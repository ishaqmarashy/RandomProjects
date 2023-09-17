#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <glm/glm.hpp>
struct ShaderProgramSource {
	std::string VertexSource;
	std::string FragmentSource;
};

enum class ShaderType {
	NONE = -1, VERTEX = 0, FRAGMENT = 1
};

class Shader {
private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void SetUniform1i(const std::string& name, int i);
	void SetUniform1f(const std::string& name, float i);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);
private:
	ShaderProgramSource ParseShader(const std::string& filepath);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
	int GetUniformLocation(const std::string& name);
};