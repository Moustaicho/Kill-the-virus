#include "Game.h"
#include <iostream>

Game::Game() : GameObject("Game")
	, engineRef(Engine::GetInstance())
{

}

Game::~Game()
{
	
}

void Game::Start()
{
	track = LoadMusicStream("Assets/Audio/Music/Octahedron - CAMERA_SURVEILLANCE.wav");
	PlayMusicStream(track);
}

void Game::Update()
{
	UpdateMusicStream(track);
	if (IsKeyPressed(KEY_SPACE))
	{
		engineRef->LoadScene("MenuScene");
	}
}

void Game::Draw()
{
	ClearBackground(BLANK);
}
