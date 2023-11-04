#pragma once
#include <vector>
#include "GameObject.h"
#include <string>

class Scene
{
private:
	std::string sceneName;
	std::vector<GameObject*> gameObjects;
	
public:
	explicit Scene(std::string name);

	void InitializeScene();
	void UpdateScene();
	void DrawScene();

	void AddGameObject(GameObject* gameobject);

	std::string GetSceneName();

};

