#pragma once
#include "Engine.h"
#include "raymath.h"
#include "FontLibrary.h"
#include "GameObject.h"
#include "UIButton.h"

#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB
#define GLSL_VERSION            100
#endif

class Menu : public GameObject
{
private:
	Engine* engineRef;
	std::string title;
	int fontSize;
	UIButton buttonPlay;
	UIButton buttonCredit;
	UIButton buttonQuit;

	Camera camera;
	Model sphereModel;
	Shader shaderVirus;
	int shaderFrame;
	int framesCounter;
	Vector3 rotation = { 0 };

	Vector2 sPosition;
	float angle = 0;
private:
	Vector2 RotateAround(Vector2 obj, Vector2 point, float angle);
public:
	Menu();
	void Start();
	void Update();
	void Draw();
};

