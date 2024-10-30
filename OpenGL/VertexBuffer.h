#pragma once
class VertexBuffer
{
private:
	unsigned int RendererID;
public:
	VertexBuffer(const void* data, unsigned int size); //size: byte, data / void*
	~VertexBuffer();
	
	void Bind() const;
	void UnBind() const;
};

