#pragma once
#include "raylib.h"
#include <map>
#include <string>

class TextureHolder
{
private:
	static TextureHolder* instance;

	std::map<std::string, Texture2D*> textures;
	std::map<std::string, RenderTexture2D*> renderTextures;
private:
	TextureHolder();
public:
	TextureHolder(TextureHolder& other) = delete;
	void operator=(const TextureHolder&) = delete;

	static TextureHolder* GetInstance();

	void AddTexture(std::string name, Texture2D* texture);
	Texture2D* GetTexture(std::string name);

	void AddRenderTexture(std::string name, RenderTexture2D* texture);
	RenderTexture2D* GetRenderTexture(std::string name);
};

