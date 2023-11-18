#include "TextureHolder.h"
TextureHolder* TextureHolder::instance = NULL;
TextureHolder::TextureHolder()
{
}

TextureHolder* TextureHolder::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new TextureHolder();
	}
	return instance;
}

void TextureHolder::AddTexture(std::string name, Texture2D texture)
{
	textures.insert(std::pair<std::string, Texture2D*>(name, &texture));
}

Texture2D* TextureHolder::GetTexture(std::string name)
{
	return textures.find(name)->second;
}

void TextureHolder::AddRenderTexture(std::string name, RenderTexture2D texture)
{
	renderTextures.insert(std::pair<std::string, RenderTexture2D*>(name, &texture));
}

RenderTexture2D* TextureHolder::GetRenderTexture(std::string name)
{
	return renderTextures.find(name)->second;
}
