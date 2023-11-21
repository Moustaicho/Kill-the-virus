#pragma once
#include "raylib.h"
#include <string>
#include <map>

//Singelton
class FontLibrary
{
private:
	static FontLibrary* instance;

	std::map<std::string,Font*> fonts;
private:
	FontLibrary();
public:
	FontLibrary(FontLibrary& other) = delete;
	void operator=(const FontLibrary&) = delete;

	static FontLibrary* GetInstance();

	void AddFont(std::string fontname, Font* newfont);
	Font* GetFont(std::string fontname);
};