#include "Game.h"
#include "Player.h"
#include <iostream>

void Game::SpawnVirus()
{
	float x = rand() % (GetMonitorWidth(engineRef->GetCurrentMonitor()) - 500) + 250;
	float y = rand() % (GetMonitorHeight(engineRef->GetCurrentMonitor()) - 500) + 250;
	//std::cout << x << "==" << (GetMonitorWidth(engineRef->GetCurrentMonitor()) - 250) << " " << y << " == " << (GetMonitorHeight(engineRef->GetCurrentMonitor()) - 250) << std::endl;
	assert(x < (GetMonitorWidth(engineRef->GetCurrentMonitor()) - 250));
	assert(y < (GetMonitorHeight(engineRef->GetCurrentMonitor()) - 250));

	Virus* newVirus = new Virus({x, y}, camera);
	std::string name;
	for (int i = 0; i < 6; i++)
	{
		char character = 'a' + rand() % 26;
		name.push_back(character);
	}
	newVirus->SetName(name);
	enemies.push_back(newVirus);	
	AddChild(newVirus);
	newVirus->Start();
}

Game::Game() : GameObject("Game")
	, engineRef(Engine::GetInstance())
	, playerRef(nullptr)
	, timer(0)
	, dmgTimer(3)
{

}

Game::~Game()
{

}

void Game::Start()
{
	timer = 0.0f;
	enemyAmount = 10;

	camera.position = Vector3{ 0.0f, 0.0f, 3.0f };
	camera.target = Vector3{ 0.0f, 0.0f, 0.0f };
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	track = *MusicHolder::GetInstance()->GetMusic("M_Game");
	PlayMusicStream(track);

	GameObject::Start();
	//We call the start method of virus in spawn so we need to put it after this start.
	for (int i = 0; i < std::floor(sqrt(enemyAmount)); i++)
	{
		SpawnVirus();
	}
}

void Game::Update()
{
	UpdateMusicStream(track);

	if (IsKeyPressed(KEY_ESCAPE))
	{
		engineRef->LoadScene("ScoreScene");
	}

	timer += GetFrameTime();
	
	if (timer >= 10)
	{
		enemyAmount += 3;
		timer = 0;
		for (int i = 0; i < std::floor(sqrt(enemyAmount)); i++)
		{
			SpawnVirus();
		}
	}
	
	if (playerRef != nullptr)
	{
		dmgTimer -= GetFrameTime();
		if (dmgTimer <= 0)
		{
			dmgTimer = 3;
			playerRef->Damage(std::floor(enemies.size()/1.3f));
		}
		
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

void Game::SetPlayerRef(Player* ref)
{
	playerRef = ref;
}

std::vector<Virus*> Game::GetVirus()
{
	return enemies;
}

void Game::RemoveVirus(Virus* virus)
{
	enemies.erase(std::remove(enemies.begin(), enemies.end(), virus), enemies.end());
	RemoveChild(virus);
}
