#pragma once
#include "Engine.h"
#include "GameObject.h"

class Player : public GameObject
{
private:
	Vector2 center;
	Vector2 move;
	bool isMoving = false;
	float speed = 5.0f;
	Engine& gameref;

	//Virus Detector
	float currentRadius = 10;
	float detectorSpeed = 1;
private:
	void MoveScreen();
public:
	Player(Engine& ref);
	void Start();
	void Update();
	void Draw();
};

