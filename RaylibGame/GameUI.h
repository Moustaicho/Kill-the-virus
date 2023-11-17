#pragma once
#include "Engine.h"
#include "UIButton.h"
#include "Game.h"
#include "GameObject.h"
#include "Fontlibrary.h"

class GameUI : public GameObject
{
private:
	Engine* engineRef;
	Game* gameref;
	Vector2 center;

	//Virus Detector
	Vector2 offsetRadar = { 150, -150 };
	float currentRadius = 10;
	float detectorSpeed = 50;

	int screenWidth;
	int screenHeight;

	std::string quitText;

	std::string scoreUI;
	float scoreSize = 25;

	bool showDebug = false;
private:
	void FindVirus();
public:
	GameUI(Game* ref);

	void Start();
	void Update();
	void Draw();
	void End();
};

