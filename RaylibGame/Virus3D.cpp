#include "Virus3D.h"

Virus3D::Virus3D(Camera& camera) : GameObject("Virus3D")
	, camera(camera)
{
}

void Virus3D::Start()
{
	target = *TextureHolder::GetInstance()->GetRenderTexture("RT_Virus");

	sphere = *ModelHolder::GetInstance()->GetMesh("Mesh_Virus");
	sphereModel = *ModelHolder::GetInstance()->GetModel("Model_Virus");

	shaderVirus = *ShaderHolder::GetInstance()->GetShader("S_Virus");

	Texture texDiffuse = *TextureHolder::GetInstance()->GetTexture("plasma");
	sphereModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texDiffuse;

	Texture texMask = *TextureHolder::GetInstance()->GetTexture("mask");
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
#include <iostream>
void Virus3D::Draw()
{
	if (GetPosition().x >= -limitDrawThreshold && GetPosition().x <= 500+limitDrawThreshold || GetPosition().y >= -limitDrawThreshold && GetPosition().y <= 500 + limitDrawThreshold)
	{
		DrawTexture(target.texture, GetPosition().x, GetPosition().y, WHITE);
	}
}

void Virus3D::End()
{

}
