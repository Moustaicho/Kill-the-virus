#pragma once
#include "Engine.h"
#include "GameObject.h"
#include "Virus.h"
#include "MusicHolder.h"
class Player;
class Game : public GameObject
{
private:
	Engine* engineRef;
	Player* playerRef;
	Music track;

	std::vector<Virus*> enemies;

	Camera camera;

	float timer;
	float dmgTimer;
	int enemyAmount;
private:
	void SpawnVirus();
public:
	Game();
	~Game();
	void Start();
	void Update();
	void Draw();
	void End();

	void SetPlayerRef(Player* ref);

	std::vector<Virus*> GetVirus();
	void RemoveVirus(Virus* virus);
};

