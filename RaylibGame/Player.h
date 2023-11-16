#pragma once
#include "Engine.h"
#include "GameObject.h"

class Player : public GameObject
{
private:
	Vector2 move;
	bool isMoving = false;
	float speed = 5.0f;
	Engine* engineRef;

	int score;

private:
	void MoveScreen();
public:
	Player();
	void Start();
	void Update();
	void Draw();
	void End();
};

