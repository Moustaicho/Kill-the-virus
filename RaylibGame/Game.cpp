#include "Game.h"
#include <iostream>

void Game::SpawnVirus()
{
	float x = rand() % (GetMonitorWidth(engineRef->GetCurrentMonitor()) - 500) + 250;
	float y = rand() % (GetMonitorHeight(engineRef->GetCurrentMonitor()) - 500) + 250;
	//std::cout << x << "==" << (GetMonitorWidth(engineRef->GetCurrentMonitor()) - 250) << " " << y << " == " << (GetMonitorHeight(engineRef->GetCurrentMonitor()) - 250) << std::endl;
	assert(x < (GetMonitorWidth(engineRef->GetCurrentMonitor()) - 250));
	assert(y < (GetMonitorHeight(engineRef->GetCurrentMonitor()) - 250));

	Virus* newVirus = new Virus({x, y});
	enemies.push_back(newVirus);
	AddChild(newVirus);
}

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

	for (int i = 0; i < 10; i++)
	{
		SpawnVirus();
	}


	GameObject::Start();
}

void Game::Update()
{
	UpdateMusicStream(track);
	if (IsKeyPressed(KEY_SPACE))
	{
		engineRef->LoadScene("MenuScene");
	}

	GameObject::Update();
}

void Game::Draw()
{
	ClearBackground(BLANK);

	GameObject::Draw();
}

void Game::End()
{
	GameObject::End();
}

std::vector<Virus*> Game::GetVirus()
{
	return enemies;
}
