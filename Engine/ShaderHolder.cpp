#include "ShaderHolder.h"

ShaderHolder* ShaderHolder::instance = NULL;
ShaderHolder::ShaderHolder()
{
}

ShaderHolder* ShaderHolder::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new ShaderHolder();
	}
	return instance;
}

void ShaderHolder::AddShader(std::string name, Shader* shader)
{
	shaders.insert(std::pair<std::string, Shader*>(name, shader));
}

Shader* ShaderHolder::GetShader(std::string name)
{
	return shaders.find(name)->second;
}
