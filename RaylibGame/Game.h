#pragma once
#include "Engine.h"
#include "GameObject.h"
#include "Virus.h"
#include "MusicHolder.h"

class Game : public GameObject
{
private:
	Engine* engineRef;
	Music track;

	std::vector<Virus*> enemies;

	Camera camera;
private:
	void SpawnVirus();
public:
	Game();
	~Game();
	void Start();
	void Update();
	void Draw();
	void End();

	std::vector<Virus*> GetVirus();
};

