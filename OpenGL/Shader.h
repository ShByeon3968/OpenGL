#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	unsigned int ID; // 쉐이더 프로그램 ID
	Shader(const char* vertexPath, const char* fragmentPath);
	void Use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
private:
	void checkCompileErrors(unsigned int shader, std::string type);
};

