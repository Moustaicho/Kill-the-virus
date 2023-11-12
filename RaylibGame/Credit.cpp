#include "Credit.h"


Credit::Credit() : GameObject("Credit")
	, engineRef(Engine::GetInstance())
	, title("CREDITS")
	, creator("Made by Jay Hriscu")
	, music("Music on Bandcamp: Octahedron")
	, sizeTitle(50)
	, sizeCreator(30)
	, sizeMusic(30)
	, buttonBack()
{
	font = FontLibrary::GetInstance()->GetFont("Monto");

	AddChild(&buttonBack);
}

void Credit::Start()
{
	buttonBack.SetText("BACK");
	buttonBack.SetTextSize(25);
	buttonBack.SetPosition({ engineRef->GetWindow()->GetSize().x / 2.0f - buttonBack.GetButtonBox().width / 2.0f, engineRef->GetWindow()->GetSize().y - 100.0f });
	buttonBack.CenterText();
	buttonBack.actionFunction = []()
	{
		Engine* engine = Engine::GetInstance();
		engine->LoadScene("MenuScene");
	};

	GameObject::Start();
}

void Credit::Update()
{
	GameObject::Update();
}

void Credit::Draw()
{
	ClearBackground(BLANK);
	DrawTextEx(font, title.c_str(), { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(font, title.c_str(), sizeTitle, 5).x / 2, 50 }, sizeTitle, 5, DARKGREEN);
	DrawTextEx(font, creator.c_str(), { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(font, creator.c_str(), sizeCreator, 1).x / 2, 150 }, sizeCreator, 1, DARKGREEN);
	DrawTextEx(font, music.c_str(), { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(font, music.c_str(), sizeMusic, 1).x / 2, 200 }, sizeMusic, 1, DARKGREEN);

	GameObject::Draw();
}
