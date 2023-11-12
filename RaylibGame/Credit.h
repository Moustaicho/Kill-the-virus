#pragma once
#include "Engine.h"
#include "FontLibrary.h"
#include "GameObject.h"
#include "UIButton.h"

class Credit : public GameObject
{
private:
	Engine* engineRef;

	Font font;

	std::string title;
	std::string creator;
	std::string music;

	int sizeTitle;
	int sizeCreator;
	int sizeMusic;

	UIButton buttonBack;
public:
	Credit();

	void Start();
	void Update();
	void Draw();
};

