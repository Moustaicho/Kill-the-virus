#pragma once
#include "raylib.h"
#include <map>
#include <string>
class ShaderHolder
{
private:
	static ShaderHolder* instance;

	std::map<std::string, Shader*> shaders;
private:
	ShaderHolder();
public:
	ShaderHolder(ShaderHolder& other) = delete;
	void operator=(const ShaderHolder&) = delete;

	static ShaderHolder* GetInstance();

	void AddShader(std::string name, Shader* shader);
	Shader* GetShader(std::string name);
};

