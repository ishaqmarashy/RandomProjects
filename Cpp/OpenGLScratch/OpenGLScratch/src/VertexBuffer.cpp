#include "VertexBuffer.h"

/*
//give unsigned int to open gl to get id
unsigned int buffer;
//1 is for the number of buffers we want to generate
glGenBuffers(1, &buffer);
//select buffer  and specify what kind of data it is
//by using array buffer we say that it is an array of data
glBindBuffer(GL_ARRAY_BUFFER, buffer);
//specify size of buffer - the data of the buffer- how it will be used and what its used for
glBufferData(GL_ARRAY_BUFFER, 2*6 * sizeof(float),positions,GL_STATIC_DRAW);
//glBindBuffer(GL_ARRAY_BUFFER, 0); //0 unbinds all buffers
glEnableVertexAttribArray(0);
//index specify what vertexarray is bound to the buffer 0 is current (vao) - size per vertex - type - normalize 0-1?? - how much to move forward to get to next attribute- pointer to starting coordinate you may need to cast
//this binds the buffer with the vao
glVertexAttribPointer(0, 2,GL_FLOAT, GL_FALSE, sizeof(float) * 2, (const void*)0);
glEnableVertexAttribArray(0);
*/

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	glGenBuffers(1, &m_RenderID);
	glBindBuffer(GL_ARRAY_BUFFER, m_RenderID);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() 
{
	glDeleteBuffers(1, &m_RenderID);
}

void VertexBuffer::Bind() const 
{
	glBindBuffer(GL_ARRAY_BUFFER, m_RenderID);
}

void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
