#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Texture {
private:
	unsigned int m_RenderID;
	std::string m_FiledPath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot=0) const;
	void Unbind() const;

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
};