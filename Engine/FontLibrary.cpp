#include "FontLibrary.h"
#include <assert.h>

FontLibrary* FontLibrary::instance = NULL;
FontLibrary::FontLibrary()
{
	Font fontDefault = GetFontDefault();
	fonts.insert(std::pair<std::string, Font>("Default", fontDefault));
}

FontLibrary* FontLibrary::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new FontLibrary();
	}
	return instance;
}

void FontLibrary::AddFont(std::string fontname, Font newfont)
{
	fonts.insert(std::pair<std::string, Font>(fontname, newfont));
}

Font FontLibrary::GetFont(std::string name)
{
	//assert(fonts.find(name) != fonts.end);
	return fonts.find(name)->second;
}