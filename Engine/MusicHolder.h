#pragma once
#include "raylib.h"
#include <map>
#include <string>
class MusicHolder
{
private:
	static MusicHolder* instance;

	std::map<std::string, Music*> tracks;
private:
	MusicHolder();
public:
	MusicHolder(MusicHolder& other) = delete;
	void operator=(const MusicHolder&) = delete;

	static MusicHolder* GetInstance();

	void AddMusic(std::string name, Music music);
	Music* GetMusic(std::string name);
};

