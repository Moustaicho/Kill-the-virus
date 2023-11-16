#pragma once
#include "GameObject.h"
#include "TextureHolder.h"
#include "raymath.h"
#include "Virus3D.h"

class Virus : public GameObject
{
private:
	int health;
	Vector2 screenPosition;
	Virus3D* virusModel;

public:
	Virus();
	Virus(Vector2 position);
	~Virus();

	void Start();
	void Update();
	void Draw();
	void End();

	Vector2 GetScreenPosition();
};

