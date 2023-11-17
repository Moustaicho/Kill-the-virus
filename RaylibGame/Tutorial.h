#pragma once
#include "Engine.h"
#include "GameObject.h"
#include "UIButton.h"
#include "FontLibrary.h"

class Tutorial : public GameObject
{
private:
	Engine* engineRef;
	std::string title;
	std::string description;

	UIButton buttonBack;

	int fontSizeTitle;
	int fontSizeDescription;
public:
	Tutorial();

	void Start();
	void Update();
	void Draw();
	void End();
};

