#include "Scene.h"
#include <iostream>

Scene::Scene(std::string name = "Scene")
{
	this->sceneName = name;
}

void Scene::InitializeScene()
{
	for (GameObject* gameObject : gameObjects)
	{
		if (gameObject->IsActive())
		{
			gameObject->Start();
		}
	}
}

void Scene::UpdateScene()
{
	for (GameObject* gameObject : gameObjects)
	{
		if (gameObject->IsActive())
		{
			gameObject->Update();
		}
	}
}

void Scene::DrawScene()
{
	for (GameObject* gameObject : gameObjects)
	{
		if (gameObject->IsActive())
		{
			gameObject->Draw();
		}
	}
}

void Scene::AddGameObject(GameObject* gameobject)
{
	gameobject->SetId(gameObjects.size());
	gameObjects.push_back(gameobject);
}

std::string Scene::GetSceneName()
{
	return sceneName;
}