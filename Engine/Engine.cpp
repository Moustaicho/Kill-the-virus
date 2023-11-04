#include "Engine.h"


Engine::Engine()
	: window(new Window(800, 450, "KILL THE VIRUS"))
	, backgroundColor(RAYWHITE)
{
	window->SetPosition(GetMonitorWidth(currentMonitor) / 2 - window->GetSize().x / 2.0f, GetMonitorHeight(currentMonitor) / 2 - window->GetSize().y / 2.0f);

}

void Engine::Initialize()
{
	scenes[currentScene]->InitializeScene();

	SetTargetFPS(60);
}
void Engine::Update()
{
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		//Update inputs here

		//Update objects here
		scenes[currentScene]->UpdateScene();

		BeginDrawing();
		//Draw game objects here
		ClearBackground(backgroundColor);

		scenes[currentScene]->DrawScene();

		//ClearBackground(RAYWHITE);
		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
		//DrawText(std::to_string(GetFPS()).c_str(), 10, 10, 20, GREEN);


		EndDrawing();
	}
	Engine::UnInitialize();
}
void Engine::UnInitialize()
{
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
