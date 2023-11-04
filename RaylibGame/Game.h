#pragma once
#include "Engine.h"
#include "GameObject.h"

class Game : public GameObject
{
private:
	Engine& gameref;
public:
	Game(Engine& ref);
	void Start();
	void Update();
	void Draw();
};

