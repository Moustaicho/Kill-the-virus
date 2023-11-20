#include "Score.h"

Score::Score() : GameObject("Score")
	, engineRef(Engine::GetInstance())
	, buttonMenu()
	, title("GAME OVER")
	, description("YOU SCORED")
	, score("000000")
{
	AddChild(&buttonMenu);
}

void Score::Start()
{
	track = *MusicHolder::GetInstance()->GetMusic("M_GameOver");
	PlayMusicStream(track);

	engineRef->ShowCustomCursor(true);

	buttonMenu.SetText("MENU");
	buttonMenu.SetTextSize(25);
	buttonMenu.SetPosition({ engineRef->GetWindow()->GetSize().x / 2.0f - buttonMenu.GetButtonBox().width / 2.0f, engineRef->GetWindow()->GetSize().y - 100.0f });
	buttonMenu.CenterText();
	buttonMenu.actionFunction = []()
		{
			Engine* engine = Engine::GetInstance();
			engine->LoadScene("MenuScene");
		};
	buttonMenu.SetBaseColor({ 0,255,0,100 });
	buttonMenu.SetHoverColor({ 0,255,0,255 });
	buttonMenu.SetClickColor({ 100,255,100,255 });

	GameObject::Start();
}

void Score::Update()
{
	UpdateMusicStream(track);
	GameObject::Update();
}

void Score::Draw()
{
	ClearBackground(BLANK);
	DrawTextEx(FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), 50, 5).x / 2,20}, 50, 5, { 0,255,0,200 });
	DrawTextEx(FontLibrary::GetInstance()->GetFont("Monto"), description.c_str(), { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(FontLibrary::GetInstance()->GetFont("Monto"), description.c_str(), 50, 1).x / 2,150}, 50, 1, { 0,255,0,200 });
	DrawTextEx(FontLibrary::GetInstance()->GetFont("Monto"), score.c_str(), { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(FontLibrary::GetInstance()->GetFont("Monto"), score.c_str(), 60, 1).x / 2,250-30}, 60, 1, { 255,0,0,200 });

	GameObject::Draw();
}

void Score::End()
{

	GameObject::End();
}

void Score::SetResult(int score)
{
	std::string n = std::to_string(score);
	size_t s = 6;
	int precision = 6 - std::min(s, n.size());
	n.insert(0, precision, '0');
	this->score = n;
}
