#include "Menu.h"


Vector2 Menu::RotateAround(Vector2 obj, Vector2 point, float angle)
{
	float s = sin(angle);
	float c = cos(angle);

	float x1 = obj.x - point.x;
	float y1 = obj.y - point.y;

	float x2 = x1 * c - y1 * s;
	float y2 = x1 * s+ y1 * c;

	return { x2 + point.x, y2 + point.y };
}

Menu::Menu() : GameObject("Menu")
	, engineRef(Engine::GetInstance())
	, title("KILL THE VIRUS")
	, fontSize(50)
	, buttonPlay()
	, buttonCredit()
	, buttonQuit()
{
	AddChild(&buttonPlay);
	AddChild(&buttonCredit);
	AddChild(&buttonQuit);
}

void Menu::Start()
{	
	buttonPlay.SetText("PLAY");
	buttonPlay.SetTextSize(25);
	buttonPlay.SetPosition({ engineRef->GetWindow()->GetSize().x / 2.0f - buttonPlay.GetButtonBox().width/2.0f, engineRef->GetWindow()->GetSize().y - 250.0f});
	buttonPlay.CenterText();
	buttonPlay.actionFunction = []()
	{
		Engine* engine = Engine::GetInstance();
		engine->LoadScene("GameScene");
	};

	buttonCredit.SetText("CREDITS");
	buttonCredit.SetTextSize(25);
	buttonCredit.SetPosition({ engineRef->GetWindow()->GetSize().x / 2.0f - buttonPlay.GetButtonBox().width / 2.0f, engineRef->GetWindow()->GetSize().y - 175.0f });
	buttonCredit.CenterText();
	buttonCredit.actionFunction = []()
	{
		Engine* engine = Engine::GetInstance();
		engine->LoadScene("CreditScene");
	};

	buttonQuit.SetText("QUIT");
	buttonQuit.SetTextSize(25);
	buttonQuit.SetPosition({ engineRef->GetWindow()->GetSize().x / 2.0f - buttonPlay.GetButtonBox().width / 2.0f, engineRef->GetWindow()->GetSize().y - 100.0f });
	buttonQuit.CenterText();
	buttonQuit.actionFunction = []()
	{
		Engine* engine = Engine::GetInstance();
		engine->CloseGame();
	};

	camera = { 0 };
	camera.position = Vector3{ 0.0f, 1.0f, 5.0f };    // Camera position
	camera.target = Vector3{ 0.0f, 0.0f, 0.0f };      // Camera looking at point
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 45.0f;                                // Camera field-of-view Y
	camera.projection = CAMERA_PERSPECTIVE;

	Mesh sphere = GenMeshSphere(1, 16, 16);
	sphereModel = LoadModelFromMesh(sphere);
	shaderVirus = LoadShader(0, TextFormat("Assets/Shaders/S_Virus.fs", GLSL_VERSION));

	Texture texDiffuse = LoadTexture("Assets/Shaders/plasma.png");
	sphereModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texDiffuse;

	Texture texMask = LoadTexture("Assets/Shaders/mask.png");
	sphereModel.materials[0].maps[MATERIAL_MAP_EMISSION].texture = texMask;
	shaderVirus.locs[SHADER_LOC_MAP_EMISSION] = GetShaderLocation(shaderVirus, "mask");

	// Frame is incremented each frame to animate the shader
	shaderFrame = GetShaderLocation(shaderVirus, "frame");
	sphereModel.materials[0].shader = shaderVirus;
	framesCounter = 0;

	sPosition = { engineRef->GetWindow()->GetSize().x / 2.0f - 20 - MeasureTextEx(FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), fontSize, 5).x / 2, 50 };

	GameObject::Start();
}

void Menu::Update()
{
	rotation.x += 1 * GetFrameTime();
	rotation.y += 1 * GetFrameTime();
	SetShaderValue(shaderVirus, shaderFrame, &framesCounter, SHADER_UNIFORM_INT);
	sphereModel.transform = MatrixRotateXYZ(rotation);;
	angle += 1 * GetFrameTime();
	sPosition = RotateAround(sPosition, { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), fontSize, 5).x / 2, 50 }, 1*GetFrameTime());

	GameObject::Update();
}

void Menu::Draw()
{
	ClearBackground(BLANK);
	
	DrawTextEx(FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), sPosition, fontSize, 5, { 0,255,0,255 });
	DrawTextEx(FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), fontSize, 5).x / 2, 50 }, fontSize, 5, {255,0,0,255});
	

	BeginMode3D(camera);

	DrawModel(sphereModel, Vector3{ 0.0f, 0.0f, 0 }, 1, WHITE);

	EndMode3D();

	GameObject::Draw();

}