#include "VertexBuffer.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	glGenBuffers(1,&RendererID); // 버퍼 생성
	glBindBuffer(GL_ARRAY_BUFFER, RendererID); // 바인딩(작업상태)
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW); // 작업상태 버퍼에 데이터전달

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


