#include "Tutorial.h"

Tutorial::Tutorial() : GameObject("Tutorial")
	, engineRef(Engine::GetInstance())
	, title("How To Play")
	, description("Use the {W, S, A ,D} keys to move the screen!")
	, virusMechanic("Press {SPACE} to kill the virus\n when it's in the radius!")
	, sound("Use {F2} to decrease the volume\n or {F3} to increase the volume!")
	, fontSizeTitle(50)
	, fontSizeDescription(20)
	, buttonBack()
{
	AddChild(&buttonBack);
}

void Tutorial::Start()
{
	track = *MusicHolder::GetInstance()->GetMusic("M_Game");
	PlayMusicStream(track);

	buttonBack.SetText("BACK");
	buttonBack.SetTextSize(25);
	buttonBack.SetPosition({ engineRef->GetWindow()->GetSize().x / 2.0f - buttonBack.GetButtonBox().width / 2.0f, engineRef->GetWindow()->GetSize().y - 100.0f });
	buttonBack.CenterText();
	buttonBack.actionFunction = []()
		{
			Engine* engine = Engine::GetInstance();
			engine->LoadScene("MenuScene");
		};
	buttonBack.SetBaseColor({ 0,255,0,100 });
	buttonBack.SetHoverColor({ 0,255,0,255 });
	buttonBack.SetClickColor({ 100,255,100,255 });

	GameObject::Start();
}

void Tutorial::Update()
{
	UpdateMusicStream(track);
	GameObject::Update();
}

void Tutorial::Draw()
{
	ClearBackground(BLANK);
	DrawTextEx(*FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(*FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), fontSizeTitle, 5).x / 2, 50 }, fontSizeTitle, 5, { 0,255,0,200 });
	DrawTextEx(*FontLibrary::GetInstance()->GetFont("Monto"), description.c_str(), { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(*FontLibrary::GetInstance()->GetFont("Monto"), description.c_str(), fontSizeDescription, 1).x / 2,150}, fontSizeDescription, 1, { 0,255,0,200 });
	DrawTextEx(*FontLibrary::GetInstance()->GetFont("Monto"), virusMechanic.c_str(), { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(*FontLibrary::GetInstance()->GetFont("Monto"), virusMechanic.c_str(), fontSizeDescription, 1).x / 2,200}, fontSizeDescription, 1, { 0,255,0,200 });
	DrawTextEx(*FontLibrary::GetInstance()->GetFont("Monto"), sound.c_str(), { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(*FontLibrary::GetInstance()->GetFont("Monto"), sound.c_str(), fontSizeDescription, 1).x / 2,250}, fontSizeDescription, 1, { 0,255,0,200 });
	
	GameObject::Draw();
}

void Tutorial::End()
{
}
