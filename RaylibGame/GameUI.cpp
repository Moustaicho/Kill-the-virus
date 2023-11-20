#include "GameUI.h"

GameUI::GameUI(Game* ref) : GameObject("GameUI")
    , engineRef(Engine::GetInstance())
    , gameref(ref)
    , screenWidth(GetMonitorWidth(engineRef->GetCurrentMonitor()))
    , screenHeight(GetMonitorHeight(engineRef->GetCurrentMonitor()))
    , scoreUI("000000")
    , quitText("Press 'ESC' to end")
    , offsetRadar({ 150, -150 })
    , currentRadius(10)
    , detectorSpeed(50)
    , scoreSize(25)
    , showDebug(false)
    , hpHeight(200)
    , hackWidth(0)
    , isHacking(false)
{

}

void GameUI::FindVirus()
{
    for (Virus* enemy : gameref->GetVirus())
    {
        Vector2 position = enemy->GetScreenPosition();
        float x =  ((-GetWindowPosition().x-250 + position.x) / screenWidth) * 200;
        float y = ((-GetWindowPosition().y-250 + position.y) / screenHeight) * 200;
        
        if (CheckCollisionCircles({ center.x + offsetRadar.x, center.y + offsetRadar.y }, 100, { center.x + offsetRadar.x + x, center.y + offsetRadar.y + y }, 5))
        {
            if (CheckCollisionCircles({ center.x + offsetRadar.x, center.y + offsetRadar.y }, currentRadius-5, { center.x + offsetRadar.x + x, center.y + offsetRadar.y + y }, 5))
            {
                DrawCircle(center.x + offsetRadar.x + x, center.y + offsetRadar.y + y, 5, { 255, 0, 0, 255 });
            }
        }
       
    }
}

void GameUI::DisplayKillingVirus()
{
    std::string text = "KILLING VIRUS: " + hackedVirusName;
    if (hackWidth > 300) hackWidth = 300;
    DrawTextEx(FontLibrary::GetInstance()->GetFont("Monto"), text.c_str(), {center.x - MeasureTextEx(FontLibrary::GetInstance()->GetFont("Monto"), text.c_str(), 20, 1).x / 2.0f, engineRef->GetWindow()->GetSize().y - 80.0f}, 20, 1, GREEN);
    DrawRectangle(center.x - 300 / 2.0, engineRef->GetWindow()->GetSize().y - 50, hackWidth, 35, { 0,0,255,100 });
    DrawRectangleLines(center.x - 150, engineRef->GetWindow()->GetSize().y - 50, 300, 35, GREEN);
}

void GameUI::Start()
{
    engineRef->ShowCustomCursor(false);
    center = { engineRef->GetWindow()->GetSize().x / 2.0f, engineRef->GetWindow()->GetSize().y / 2.0f };

    GameObject::Start();
}

void GameUI::Update()
{
    if (IsKeyPressed(KEY_F1))
    {
        showDebug = !showDebug;
    }


    currentRadius += detectorSpeed * GetFrameTime();
    if (currentRadius >= 100)
    {
        currentRadius = 1;
    }

    //bool virusHit = CheckCollisionCircles({ center.x, center.y }, 100, { (-GetWindowPosition().x + 250), (-GetWindowPosition().y + 250) }, 20);
    //std::cout << "Virus detected: " << virusHit << std::endl;

    GameObject::Update();
}

void GameUI::Draw()
{
    if (showDebug)
    {
        DrawFPS(10, 10);
    }
    std::string textSore = "SCORE: " + scoreUI;
    DrawTextEx(FontLibrary::GetInstance()->GetFont("Monto"), textSore.c_str(), { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(FontLibrary::GetInstance()->GetFont("Monto"), textSore.c_str(), scoreSize, 5).x / 2, 10 }, scoreSize, 1, { 0,255,0,255 });
    DrawTextEx(FontLibrary::GetInstance()->GetFont("Monto"), quitText.c_str(), { 10, 15 }, 15, 1, { 0,255,0,255 });

    DrawCircleLines(center.x, center.y , 100, WHITE);
    
    DrawCircle(center.x + offsetRadar.x, center.y + offsetRadar.y, 100, { 0, 64, 24, 255 });
    DrawCircleLines(center.x + offsetRadar.x, center.y + offsetRadar.y, 100, WHITE);
    DrawCircleLines(center.x + offsetRadar.x, center.y + offsetRadar.y, 80, WHITE);
    DrawCircleLines(center.x + offsetRadar.x, center.y + offsetRadar.y, 60, WHITE);
    DrawCircleLines(center.x + offsetRadar.x, center.y + offsetRadar.y, 40, WHITE);
    DrawRing({ center.x + offsetRadar.x, center.y + offsetRadar.y }, currentRadius - 5, currentRadius, 0, 360, 24, { 0, 255, 0, 255 });

    FindVirus();

    DrawTextEx(FontLibrary::GetInstance()->GetFont("Monto"), "HP", { 13.5f, engineRef->GetWindow()->GetSize().y - 270.0f}, 20, 1, GREEN);
    DrawRectangle(10, engineRef->GetWindow()->GetSize().y - 50 - hpHeight, 25, hpHeight, {200, 0, 0, 100});
    DrawRectangleLines(10, engineRef->GetWindow()->GetSize().y - 250, 25, 200, GREEN);

    if (isHacking)
    {
        DisplayKillingVirus();
    }

    GameObject::Draw();
}

void GameUI::End()
{
    GameObject::End();
}

void GameUI::SetHackUIState(bool state)
{
    isHacking = state;
}

void GameUI::SetVirusName(std::string name)
{
    hackedVirusName = name;
}

void GameUI::SetVirusHealth(int health)
{
    hackWidth = 300 - health;
}

void GameUI::SetScore(int score)
{
    std::string n = std::to_string(score);
    size_t s = 6;
    int precision = 6 - std::min(s, n.size());
    n.insert(0, precision, '0');
    scoreUI = n;
}

void GameUI::SetPlayerHealth(int health)
{
    hpHeight = health * 2;
}
