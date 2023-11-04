#include "Menu.h"


Menu::Menu(Engine& ref) : GameObject("Menu")
	, gameref(ref)
{
}

void Menu::Start()
{

}

void Menu::Update()
{
	if (IsKeyPressed(KEY_SPACE))
	{
		gameref.LoadScene("GameScene");
	}
}

void Menu::Draw()
{
	ClearBackground(DARKBLUE);
}
