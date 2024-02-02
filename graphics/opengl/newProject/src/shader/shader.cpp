#include <glad/glad.h>

#include "shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "log/log.h"

Shader::Shader(const std::string & vertexShaderPath, const std::string & fragmentShaderPath)
{
	// 1. retrieve the vertex/fragment source code from disk file
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	std::string vertexCode;
	std::string fragmentCode;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vShaderFile.open(vertexShaderPath);
		fShaderFile.open(fragmentShaderPath);

		std::stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		log("ERROR::SHDER::FILE_NOT_SUCCESSFULLY_READ\n");
        return;
	}
	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	// 2. compile shader
	int success;
	char infoLog[512];
	// vertex shader
	unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		log("ERROR::SHADER::VERTEX::COMPILATION_FAILD\n");
		log(infoLog);
	}
	// fragment shader
	unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		log("ERROR::SHADER::FRAGMENT::COMPILATION_FAILD\n");
		log(infoLog);
	}

	// 3. link shader
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		log("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
		log(infoLog);
	}
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::use() const
{
	glUseProgram(ID);
}

void Shader::setBool(const std::string & name, bool value)
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setFloat(const std::string & name, float value)
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setInt(const std::string & name, int value)
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
