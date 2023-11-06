#include "Menu.h"


Menu::Menu(Engine& ref) : GameObject("Menu")
	, gameref(ref)
{
	SetPosition({ 100,100 });
	std::cout << std::to_string(GetPosition().x) << " " << std::to_string(GetPosition().y) << std::endl;
}

void Menu::Start()
{
	std::cout << "Parent" << std::endl;
}

void Menu::Update()
{
	Vector2 newPos = GetPosition() + Vector2{0.0f, 1.0f};
	this->SetPosition(newPos);
	if (IsKeyPressed(KEY_SPACE))
	{
		gameref.LoadScene("GameScene");
	}
	GameObject::Update();
}

void Menu::Draw()
{
	ClearBackground(DARKBLUE);
	DrawText("Parent", GetPosition().x, GetPosition().y, 50, WHITE);
	GameObject::Draw();
}
