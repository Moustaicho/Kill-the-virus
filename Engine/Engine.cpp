#include "Engine.h"

Engine* Engine::instance = NULL;
Engine::Engine()
	: window(new Window(500, 500, "KILL THE VIRUS"))
	, backgroundColor(RAYWHITE)
{
	window->SetPosition(GetMonitorWidth(currentMonitor) / 2 - window->GetSize().x / 2.0f, GetMonitorHeight(currentMonitor) / 2 - window->GetSize().y / 2.0f);
	SetExitKey(KEY_NULL);
}

Engine* Engine::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Engine();
	}
	return instance;
}

void Engine::Initialize()
{
	InitAudioDevice();
	scenes[currentScene]->InitializeScene();

	SetTargetFPS(60);
}
void Engine::Update()
{
	while (!WindowShouldClose() && !closeGame)    // Detect window close button or ESC key
	{
		scenes[currentScene]->UpdateScene();

		BeginDrawing();

		ClearBackground(backgroundColor);

		scenes[currentScene]->DrawScene();

		EndDrawing();
	}
	Engine::UnInitialize();
}
void Engine::UnInitialize()
{
	CloseAudioDevice();
	CloseWindow();
}

void Engine::AddScene(Scene* newScene)
{
	if (scenes.empty())
	{
		currentScene = newScene->GetSceneName();
	}

	scenes.insert(std::pair<std::string, Scene*>(newScene->GetSceneName(), newScene));
}

void Engine::LoadScene(std::string name)
{
	assert(scenes.find(name) != scenes.end() && "Could not find Scene!");

	currentScene = name;
	scenes[currentScene]->InitializeScene();
}

Window* Engine::GetWindow()
{
	return window;
}

void Engine::SetBackgroundColor(Color color)
{
	backgroundColor = color;
}

int Engine::GetCurrentMonitor()
{
	return currentMonitor;
}

void Engine::CloseGame()
{
	closeGame = true;
}