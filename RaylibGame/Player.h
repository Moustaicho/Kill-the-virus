#pragma once
#include "Engine.h"
#include "Game.h"
#include "GameUI.h"
#include "Score.h"
#include "GameObject.h"

class Player : public GameObject
{
private:
	Vector2 move;
	bool isMoving;
	float speed;
	Engine* engineRef;

	int health;
	int healthGot;
	int score;

	Game* gameRef;
	GameUI* gameUIRef;
	Score* scoreRef;

	float dmgTimer;
	int hackSpeed;
private:
	void MoveScreen();
	void StartHacking(Virus* virus);
public:
	Player();
	void Start();
	void Update();
	void Draw();
	void End();

	void SetGameRef(Game* game);
	void SetGameUIRef(GameUI* gameUI);
	void SetScoreRef(Score* score);
	void Damage(int dmg);
};

