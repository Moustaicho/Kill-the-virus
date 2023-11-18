#include "Game.h"
#include <iostream>

void Game::SpawnVirus()
{
	float x = rand() % (GetMonitorWidth(engineRef->GetCurrentMonitor()) - 500) + 250;
	float y = rand() % (GetMonitorHeight(engineRef->GetCurrentMonitor()) - 500) + 250;
	//std::cout << x << "==" << (GetMonitorWidth(engineRef->GetCurrentMonitor()) - 250) << " " << y << " == " << (GetMonitorHeight(engineRef->GetCurrentMonitor()) - 250) << std::endl;
	assert(x < (GetMonitorWidth(engineRef->GetCurrentMonitor()) - 250));
	assert(y < (GetMonitorHeight(engineRef->GetCurrentMonitor()) - 250));

	Virus* newVirus = new Virus({x, y}, camera);
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
	camera.position = Vector3{ 0.0f, 0.0f, 3.0f };
	camera.target = Vector3{ 0.0f, 0.0f, 0.0f };
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	track = *MusicHolder::GetInstance()->GetMusic("M_Game");
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
	if (IsKeyPressed(KEY_ESCAPE))
	{
		engineRef->LoadScene("ScoreScene");
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
	enemies.clear();
	GameObject::End();
	RemoveAllChildren();
}

std::vector<Virus*> Game::GetVirus()
{
	return enemies;
}
