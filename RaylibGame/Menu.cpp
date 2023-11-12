#include "Menu.h"


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

	GameObject::Start();
}

void Menu::Update()
{
	GameObject::Update();
}

void Menu::Draw()
{
	ClearBackground(DARKGREEN);
	DrawTextEx(FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), {engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(FontLibrary::GetInstance()->GetFont("Monto"), title.c_str(), fontSize, 5).x / 2, 50}, fontSize, 5, BLACK);

	GameObject::Draw();

}