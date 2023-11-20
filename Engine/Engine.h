#pragma once
#include <assert.h>
#include <iostream>
#include <string>
#include <map>

#include "raylib.h"

#include "TextureHolder.h"
#include "Scene.h"
#include "Window.h"

//Singelton
class Engine
{
private:
	static Engine* instance;

	bool closeGame;

	int currentMonitor;
	std::string currentScene;
	std::map<std::string, Scene*> scenes;
	Window* window;
	Color backgroundColor;

	bool customCursor;
	bool showCustomCursor;
	Texture* textureCursor;
private:
	Engine();
public:
	Engine(Engine &other) = delete;
	void operator=(const Engine&) = delete;

	static Engine* GetInstance();

	void Initialize();
	void Update();
	void UnInitialize();

	void AddScene(Scene* newScene);
	void LoadScene(std::string name);
	Scene* GetCurrentScene();

	Window* GetWindow();
	void SetBackgroundColor(Color color);
	int GetCurrentMonitor();

	void CloseGame();

	void SetCustomCursor(Texture texture);
	void ShowCustomCursor(bool state);
};