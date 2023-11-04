#pragma once
#include "Engine.h"
#include "GameObject.h"

class Menu : public GameObject
{
private:
	Engine& gameref;
public:
	Menu(Engine& ref);
	void Start();
	void Update();
	void Draw();
};

