#include "MusicHolder.h"

MusicHolder* MusicHolder::instance = NULL;
MusicHolder::MusicHolder()
{

}

MusicHolder* MusicHolder::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new MusicHolder();
	}
	return instance;
}

void MusicHolder::AddMusic(std::string name, Music* music)
{
	tracks.insert(std::pair<std::string, Music*>(name, music));
}

Music* MusicHolder::GetMusic(std::string name)
{
	return tracks.find(name)->second;
}
