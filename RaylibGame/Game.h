#pragma once
#include "Engine.h"
#include "GameObject.h"

class Game : public GameObject
{
private:
	Engine* engineRef;
	Music track;
public:
	Game();
	~Game();
	void Start();
	void Update();
	void Draw();
};

