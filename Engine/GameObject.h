#pragma once
#include "raylib.h"
#include <vector>
#include <string>

class GameObject
{
private:
	int id;
	std::string name;
	Texture2D texture;
	Vector2 position;
	Vector2i scale;
	float rotation;

	bool isActive;

	std::vector<GameObject*> children;
public:
	GameObject(std::string name, Vector2 position = { 0, 0 }, float rotation = 0);

	virtual ~GameObject() {};

	bool IsActive();

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

