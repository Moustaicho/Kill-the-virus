#pragma once
#include "Engine.h"
#include "GameObject.h"
#include "UIButton.h"

class Score : public GameObject
{
private:
	Engine* engineRef;

	std::string title;
	std::string description;
	std::string score;

	UIButton buttonMenu;
public:
	Score();

	void Start();
	void Update();
	void Draw();
	void End();
};

