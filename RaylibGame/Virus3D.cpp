#include "Virus3D.h"

Virus3D::Virus3D() : GameObject("Virus3D")
{
}

void Virus3D::Start()
{
	target = LoadRenderTexture(50, 50);

	camera.position = Vector3{ 0.0f, 0.0f, 3.0f };
	camera.target = Vector3{ 0.0f, 0.0f, 0.0f };
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	sphere = GenMeshSphere(1, 16, 16);
	sphereModel = LoadModelFromMesh(sphere);

	shaderVirus = LoadShader(TextFormat("Assets/Shaders/S_Virus.vs", GLSL_VERSION), TextFormat("Assets/Shaders/S_Virus.fs", GLSL_VERSION));

	Texture texDiffuse = TextureHolder::GetInstance()->GetTexture("plasma");
	sphereModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texDiffuse;

	Texture texMask = TextureHolder::GetInstance()->GetTexture("mask");
	sphereModel.materials[0].maps[MATERIAL_MAP_EMISSION].texture = texMask;
	shaderVirus.locs[SHADER_LOC_MAP_EMISSION] = GetShaderLocation(shaderVirus, "mask");

	// Frame is incremented each frame to animate the shader
	shaderFrame = GetShaderLocation(shaderVirus, "frame");
	sphereModel.materials[0].shader = shaderVirus;
	framesCounter = 0;
}

void Virus3D::Update()
{
	rotation.x += 1 * GetFrameTime();
	rotation.y += 1 * GetFrameTime();
	SetShaderValue(shaderVirus, shaderFrame, &framesCounter, SHADER_UNIFORM_INT);
	sphereModel.transform = MatrixRotateXYZ(rotation);

	BeginTextureMode(target);
	ClearBackground(BLANK);
	DrawCircle(200, 200, 50, PURPLE);
	BeginMode3D(camera);
	DrawModel(sphereModel, Vector3{ 0, 0, 0 }, 1, WHITE);
	EndMode3D();
	EndTextureMode();
}

void Virus3D::Draw()
{
	DrawTexture(target.texture, GetPosition().x, GetPosition().y, WHITE); //This should 
}

void Virus3D::End()
{
	UnloadMesh(sphere);
	UnloadShader(shaderVirus);
}
