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

	GameObject* parent;
	std::vector<GameObject*> children;
public:
	GameObject(std::string name, Vector2 position = { 0, 0 }, float rotation = 0);
	virtual ~GameObject() {};

	void SetId(int id);
	void SetActive(bool active);
	bool IsActive();
	void SetPosition(Vector2 position);
	Vector2 GetPosition();
	void SetRotation(float rotation);

	void SetParent(GameObject* parent);
	GameObject* GetParent();
	void AddChild(GameObject* child);
	GameObject* GetChildAt(int i);
	void RemoveAllChildren();

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void End() = 0;
};

