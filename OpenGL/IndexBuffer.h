#pragma once
#include <glad/glad.h>

class IndexBuffer
{
	unsigned int RendererID;
	unsigned int Count;
public:
	IndexBuffer(const unsigned int* data, unsigned int count); //index�� (��κ�) unsigned int* Ÿ��. count�� ����(size�� �ٸ�)
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetCount() const { return Count; }
};

