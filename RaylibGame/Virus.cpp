#include "Virus.h"
#include <iostream>

Virus::Virus() : GameObject("Virus")
{

}

Virus::Virus(Vector2 position) : GameObject("Virus")
{
	screenPosition = position;
}

Virus::~Virus()
{
}

void Virus::Start()
{
	virusModel = new Virus3D();
	AddChild(virusModel);
	GameObject::Start();
}

void Virus::Update()
{
	SetPosition({ -GetWindowPosition().x + screenPosition.x, -GetWindowPosition().y + screenPosition.y });
	virusModel->SetPosition({ GetPosition().x-25, GetPosition().y-25 });
	GameObject::Update();
}

void Virus::Draw()
{
	//DrawCircle(GetPosition().x, GetPosition().y, 20, {255, 0, 0, 255});
	GameObject::Draw();
}

void Virus::End()
{
	GameObject::End();
}

Vector2 Virus::GetScreenPosition()
{
	return screenPosition;
}
