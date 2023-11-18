#pragma once
#include "GameObject.h"
#include "TextureHolder.h"
#include "ShaderHolder.h"
#include "ModelHolder.h"
#include "raymath.h"

#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB
#define GLSL_VERSION            100
#endif

class Virus3D : public GameObject
{
private:
	Camera& camera;
	Mesh sphere;
	Model sphereModel;
	Shader shaderVirus;
	int shaderFrame;
	int framesCounter;
	Vector3 rotation = { 0 };

	RenderTexture2D target;

	int limitDrawThreshold = 15;
public:
	Virus3D(Camera& camera);
	void Start();
	void Update();
	void Draw();
	void End();
};

