#include "VertexBuffer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	glGenBuffers(1,&RendererID); // ���� ����
	glBindBuffer(GL_ARRAY_BUFFER, RendererID); // ���ε�(�۾�����)
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW); // �۾����� ���ۿ� ����������

}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &RendererID);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, RendererID);
}

void VertexBuffer::UnBind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


