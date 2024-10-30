#pragma once
#include <glad/glad.h>
#include <vector>

struct VertexBufferElement 
{
	unsigned int type; // �� ������ Ÿ���� ��������
	unsigned int count; // �����Ͱ� �� ������
	unsigned char normalized; // �������� normalization�� �ʿ�����

	static unsigned int GetSizeOfType(unsigned int type) 
	{
		// Ÿ�� ���� ������ �޸� ����� ��ȯ
		switch (type)
		{
			case GL_FLOAT: return 4;
			case GL_UNSIGNED_INT: return 4;
			case GL_UNSIGNED_BYTE: return 1;
		}
	}
};

class VertexBufferLayout 
{
private:
	std::vector<VertexBufferElement> Elements;
	unsigned int Stride;
public:
	VertexBufferLayout() : Stride{ 0 } {}

	template<typename T>
	void Push(unsigned int count) 
	{ 
		//static_assert(false);
	}

	template<>
	void Push<float>(unsigned int count) 
	{
		// glVertexAttribPointer()�� Element ����
		Elements.push_back({ GL_FLOAT,count,GL_FALSE });
		Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}

	template<>
	void Push<unsigned int>(unsigned int count)
	{
		// glVertexAttribPointer()�� Element ����
		Elements.push_back({ GL_UNSIGNED_INT,count,GL_FALSE });
		Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void Push<unsigned char>(unsigned int count)
	{
		// glVertexAttribPointer()�� Element ����
		Elements.push_back({ GL_UNSIGNED_BYTE,count,GL_FALSE });
		Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<VertexBufferElement>& GetElement() const { return Elements; }
	inline unsigned int GetStride() const { return Stride; }


};