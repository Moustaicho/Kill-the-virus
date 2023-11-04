#pragma once
#include <assert.h>
#include <iostream>
#include <string>
#include <map>

#include "raylib.h"

#include "Scene.h"
#include "Window.h"

class Engine
{
private:
	int currentMonitor = 0;
	std::string currentScene = "";
	std::map<std::string, Scene*> scenes;
	Window* window;
	Color backgroundColor;
private:

public:

public:
	Engine();

	void Initialize();
	void Update();
	void UnInitialize();

	void AddScene(Scene* newScene);
	void LoadScene(std::string name);

	Window* GetWindow();
	void SetBackgroundColor(Color color);
};