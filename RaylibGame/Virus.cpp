#include "Virus.h"
#include <iostream>

Virus::Virus(Camera& camera) : GameObject("Virus")
	, camera(camera)
{

}

Virus::Virus(Vector2 position, Camera& camera) : GameObject("Virus")
	, camera(camera)
{
	screenPosition = position;
}

Virus::~Virus()
{
}

void Virus::Start()
{
	virusModel = new Virus3D(camera);
	AddChild(virusModel);
	GameObject::Start();
}

void Virus::Update()
{
	SetPosition({ -GetWindowPosition().x + (int)screenPosition.x, -GetWindowPosition().y + (int)screenPosition.y });
	virusModel->SetPosition({ GetPosition().x-25, GetPosition().y-25 });
	GameObject::Update();
}

void Virus::Draw()
{
	//In case 3D models don't work use this to see where the virus is.
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
