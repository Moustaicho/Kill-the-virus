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
	, buttonTutorial()
{
	AddChild(&buttonPlay);
	AddChild(&buttonCredit);
	AddChild(&buttonQuit);
	AddChild(&buttonTutorial);
}

void Menu::Start()
{	
	engineRef->ShowCustomCursor(true);

	track = LoadMusicStream("Assets/Audio/Music/Octahedron - CAMERA_SURVEILLANCE.wav");
	PlayMusicStream(track);

	buttonPlay.SetText("PLAY");
	buttonPlay.SetTextSize(25);
	buttonPlay.SetPosition({ engineRef->GetWindow()->GetSize().x / 2.0f - buttonPlay.GetButtonBox().width/2.0f, engineRef->GetWindow()->GetSize().y - 100.0f });
	buttonPlay.CenterText();
	buttonPlay.actionFunction = []()
	{
		Engine* engine = Engine::GetInstance();
		engine->LoadScene("GameScene");
	};
	buttonPlay.SetBaseColor({0,255,0,100});
	buttonPlay.SetHoverColor({0,255,0,255});
	buttonPlay.SetClickColor({100,255,100,255});

	buttonCredit.SetText("CREDITS");
	buttonCredit.SetTextSize(25);
	buttonCredit.SetPosition({ engineRef->GetWindow()->GetSize().x - buttonPlay.GetButtonBox().width / 2.0f - 100, engineRef->GetWindow()->GetSize().y - 100.0f });
	buttonCredit.CenterText();
	buttonCredit.actionFunction = []()
	{
		Engine* engine = Engine::GetInstance();
		engine->LoadScene("CreditScene");
	};
	buttonCredit.SetBaseColor({0,0,255,100});
	buttonCredit.SetHoverColor({0,0,255,255});
	buttonCredit.SetClickColor({100,100,255,255});

	buttonQuit.SetText("QUIT");
	buttonQuit.SetTextSize(25);
	buttonQuit.SetPosition({ 100 - buttonPlay.GetButtonBox().width / 2.0f , engineRef->GetWindow()->GetSize().y - 100.0f });
	buttonQuit.CenterText();
	buttonQuit.actionFunction = []()
	{
		Engine* engine = Engine::GetInstance();
		engine->CloseGame();
	};
	buttonQuit.SetBaseColor({255,0,0,100});
	buttonQuit.SetHoverColor({255,0,0,255});
	buttonQuit.SetClickColor({255,100,100,255});

	buttonTutorial.SetText("How To Play");
	buttonTutorial.SetTextSize(25);
	buttonTutorial.SetPosition({ engineRef->GetWindow()->GetSize().x / 2.0f - buttonPlay.GetButtonBox().width / 2.0f, engineRef->GetWindow()->GetSize().y - 50.0f });
	buttonTutorial.CenterText();
	buttonTutorial.actionFunction = []()
		{
			Engine* engine = Engine::GetInstance();
			engine->LoadScene("TutorialScene");
		};
	buttonTutorial.SetBaseColor({0,0,0,0});
	buttonTutorial.SetHoverColor({0,0,0,0});
	buttonTutorial.SetClickColor({0,0,0,0});
	buttonTutorial.SetTextBaseColor({0,255,0,100});
	buttonTutorial.SetTextHoverColor({0,255,0,255});
	buttonTutorial.SetTextClickColor({255,0,0,255});

	camera = { 0 };
	camera.position = Vector3{ 0.0f, 1.0f, 5.0f };    // Camera position
	camera.target = Vector3{ 0.0f, 0.0f, 0.0f };      // Camera looking at point
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 45.0f;                                // Camera field-of-view Y
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

	sPosition = { engineRef->GetWindow()->GetSize().x / 2.0f - 20 - MeasureTextEx(FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), fontSize, 5).x / 2, 50 };

	GameObject::Start();
}

void Menu::Update()
{
	UpdateMusicStream(track);
	rotation.x += 1 * GetFrameTime();
	rotation.y += 1 * GetFrameTime();
	SetShaderValue(shaderVirus, shaderFrame, &framesCounter, SHADER_UNIFORM_INT);
	sphereModel.transform = MatrixRotateXYZ(rotation);
	angle += 1 * GetFrameTime();
	sPosition = RotateAround(sPosition, { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), fontSize, 5).x / 2, 50 }, 1*GetFrameTime());

	GameObject::Update();
}

void Menu::Draw()
{
	ClearBackground(BLANK);
	
	DrawTextEx(FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), sPosition, fontSize, 5, { 0,255,0,200 });
	DrawTextEx(FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), fontSize, 5).x / 2, 50 }, fontSize, 5, {255,0,0,200});
	

	BeginMode3D(camera);

	DrawModel(sphereModel, Vector3{ 0.0f, 0.0f, 0 }, 1, WHITE);

	EndMode3D();

	GameObject::Draw();

}

void Menu::End()
{
	UnloadMesh(sphere);
	UnloadShader(shaderVirus);
}