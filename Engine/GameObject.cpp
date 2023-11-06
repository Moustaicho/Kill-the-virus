#include "GameObject.h"

GameObject::GameObject(std::string name, Vector2 position, float rotation)
	: name(name)
	, position(position)
	, rotation(rotation)
	, scale({1, 1})
	, isActive(true)
	, parent(nullptr)
{

}

void GameObject::SetId(int id)
{
	this->id = id;
}

bool GameObject::IsActive()
{
	return isActive;
}

void GameObject::SetPosition(Vector2 position)
{
	//the child position equals the parent but then we calculate the childs position with the parent included again with the parent. idiot
	this->position = position;
}

Vector2 GameObject::GetPosition()
{
	return position;
}

void GameObject::SetRotation(float rotation)
{
	this->rotation = rotation;
}

void GameObject::SetParent(GameObject* parent)
{
	this->parent = parent;
	//need to at current object to parent children vector?
}

void GameObject::AddChild(GameObject* child)
{
	child->SetParent(this);
	child->SetPosition(this->GetPosition());
	children.push_back(child);
}

GameObject* GameObject::GetChildAt(int i)
{
	return children[i];
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
