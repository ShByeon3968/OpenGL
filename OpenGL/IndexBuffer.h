#pragma once
#include <glad/glad.h>

class IndexBuffer
{
	unsigned int RendererID;
	unsigned int Count;
public:
	IndexBuffer(const unsigned int* data, unsigned int count); //index는 (대부분) unsigned int* 타입. count는 갯수(size와 다름)
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetCount() const { return Count; }
};

