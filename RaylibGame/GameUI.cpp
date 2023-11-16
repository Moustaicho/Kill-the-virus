#include "GameUI.h"

GameUI::GameUI(Game* ref) : GameObject("GameUI")
    , engineRef(Engine::GetInstance())
    , gameref(ref)
    , screenWidth(GetMonitorWidth(engineRef->GetCurrentMonitor()))
    , screenHeight(GetMonitorHeight(engineRef->GetCurrentMonitor()))
    , scoreUI("SCORE: 000000")
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

void GameUI::Start()
{
    center = { engineRef->GetWindow()->GetSize().x / 2.0f, engineRef->GetWindow()->GetSize().y / 2.0f };
}

void GameUI::Update()
{
    if (IsKeyPressed(KEY_F1))
    {
        showDebug = !showDebug;
    }


    currentRadius += detectorSpeed;
    if (currentRadius >= 100)
    {
        currentRadius = 1;
    }

    //bool virusHit = CheckCollisionCircles({ center.x, center.y }, 100, { (-GetWindowPosition().x + 250), (-GetWindowPosition().y + 250) }, 20);
    //std::cout << "Virus detected: " << virusHit << std::endl;
}

void GameUI::Draw()
{
    if (showDebug)
    {
        DrawFPS(10, 10);
    }


    DrawTextEx(FontLibrary::GetInstance()->GetFont("Monto"), scoreUI.c_str(), { engineRef->GetWindow()->GetSize().x / 2.0f - MeasureTextEx(FontLibrary::GetInstance()->GetFont("Monto"), scoreUI.c_str(), scoreSize, 5).x / 2, 10 }, scoreSize, 1, { 0,255,0,255 });

    DrawCircleLines(center.x, center.y , 100, WHITE);
    
    DrawCircle(center.x + offsetRadar.x, center.y + offsetRadar.y, 100, { 0, 64, 24, 255 });
    DrawCircleLines(center.x + offsetRadar.x, center.y + offsetRadar.y, 100, WHITE);
    DrawCircleLines(center.x + offsetRadar.x, center.y + offsetRadar.y, 80, WHITE);
    DrawCircleLines(center.x + offsetRadar.x, center.y + offsetRadar.y, 60, WHITE);
    DrawCircleLines(center.x + offsetRadar.x, center.y + offsetRadar.y, 40, WHITE);
    DrawRing({ center.x + offsetRadar.x, center.y + offsetRadar.y }, currentRadius - 5, currentRadius, 0, 360, 24, { 0, 255, 0, 255 });

    FindVirus();
}

void GameUI::End()
{
}
