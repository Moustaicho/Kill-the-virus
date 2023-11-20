#pragma once
#include "GameObject.h"
#include "TextureHolder.h"
#include "raymath.h"
#include "Virus3D.h"

class Virus : public GameObject
{
private:
	std::string name;
	int health;
	Vector2 screenPosition;
	Virus3D* virusModel;

	Camera& camera;
public:
	Virus(Camera& camera);
	Virus(Vector2 position, Camera& camera);
	~Virus();

	void Start();
	void Update();
	void Draw();
	void End();

	Vector2 GetScreenPosition();

	void SetName(std::string name);
	std::string GetName();

	void Damage(int dmg);
	int GetHealth();
};

