#include "Game.h"
#include <iostream>

Game::Game(Engine& ref) : GameObject("Game")
	, gameref(ref)
{

}

void Game::Start()
{

}

void Game::Update()
{
	if (IsKeyPressed(KEY_SPACE))
	{
		gameref.LoadScene("MenuScene");
	}
}

void Game::Draw()
{
	ClearBackground(DARKGREEN);
	DrawText("Game", 300, 100, 20, WHITE);
}
