#include "GameObject.h"

GameObject::GameObject(std::string name, Vector2 position, float rotation)
{
	this->name = name;
	this->position = position;
	this->rotation = rotation;
	this->scale = {1, 1};
	this->isActive = true;
}

bool GameObject::IsActive()
{
	return isActive;
}

void GameObject::Start()
{
	for (GameObject* gameobject : children)
	{
		if (gameobject->IsActive())
		{
			gameobject->Start();
		}
	}
}

void GameObject::Update()
{
	for (GameObject* gameobject : children)
	{
		if (gameobject->IsActive())
		{
			gameobject->Update();
		}
	}
}

void GameObject::Draw()
{
	for (GameObject* gameobject : children)
	{
		if (gameobject->IsActive())
		{
			gameobject->Draw();
		}
	}
	//DrawTextureEx(texture, position, rotation, scale.x, WHITE);
	//DrawTexturePro();
}
