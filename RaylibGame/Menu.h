#pragma once
#include "Engine.h"
#include "FontLibrary.h"
#include "GameObject.h"
#include "UIButton.h"

class Menu : public GameObject
{
private:
	Engine* engineRef;
	std::string title;
	int fontSize;
	UIButton buttonPlay;
	UIButton buttonCredit;
	UIButton buttonQuit;
private:

public:
	Menu();
	void Start();
	void Update();
	void Draw();
};

