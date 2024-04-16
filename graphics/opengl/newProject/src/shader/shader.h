#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader
{
public:
	Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	void use() const;
	void setBool(const std::string& name, bool value);
	void setFloat(const std::string& name, float value);
	void setInt(const std::string& name, int value);
	unsigned int GetID() const { return ID; }

private:
	unsigned int ID;
};

#endif // !SHADER_H
