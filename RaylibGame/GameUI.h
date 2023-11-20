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
	Vector2 offsetRadar;
	float currentRadius;
	float detectorSpeed;

	int screenWidth;
	int screenHeight;

	std::string quitText;

	std::string scoreUI;
	float scoreSize;

	bool showDebug;

	float hpHeight;
	float hackWidth;

	std::string hackedVirusName;
	bool isHacking;
private:
	void FindVirus();

	void DisplayKillingVirus();
public:
	GameUI(Game* ref);

	void Start();
	void Update();
	void Draw();
	void End();

	void SetHackUIState(bool state);
	void SetVirusName(std::string name);
	void SetVirusHealth(int health);
	void SetScore(int score);

	void SetPlayerHealth(int health);
};

