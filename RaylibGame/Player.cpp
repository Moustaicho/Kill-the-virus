#include "Player.h"

Player::Player() : GameObject("Player")
    , engineRef(Engine::GetInstance())
    , move({0,0})
{
    
}

void Player::Start()
{
    score = 0;
    SetPosition({ GetMonitorWidth(engineRef->GetCurrentMonitor()) / 2 - engineRef->GetWindow()->GetSize().x / 2.0f, GetMonitorHeight(engineRef->GetCurrentMonitor()) / 2 - engineRef->GetWindow()->GetSize().y / 2.0f});
}

void Player::Update()
{
    move = { 0, 0 };
    if (IsKeyDown(KEY_A))
    {
        move.x = -speed;
    }
    if (IsKeyDown(KEY_D))
    {
        move.x = speed;
    }
    if (IsKeyDown(KEY_W))
    {
        move.y = -speed;
    }
    if (IsKeyDown(KEY_S))
    {
        move.y = speed;
    }
    MoveScreen();
}

void Player::Draw()
{
   
}

void Player::End()
{

}

void Player::MoveScreen()
{

    if (GetWindowPosition().x + engineRef->GetWindow()->GetSize().x >= GetMonitorWidth(engineRef->GetCurrentMonitor()))
    {
        SetPosition({ ((float)GetMonitorWidth(engineRef->GetCurrentMonitor()) - engineRef->GetWindow()->GetSize().x), GetPosition().y});
    }
    if (GetWindowPosition().x <= 0)
    {
        SetPosition({ 0, GetPosition().y });
    }

    if (GetWindowPosition().y + engineRef->GetWindow()->GetSize().y >= GetMonitorHeight(engineRef->GetCurrentMonitor()))
    {
        SetPosition({ GetPosition().x, ((float)GetMonitorHeight(engineRef->GetCurrentMonitor()) - engineRef->GetWindow()->GetSize().y) });
    }
    if (GetWindowPosition().y <= 0)
    {
        SetPosition({GetPosition().x,0});
    }

    SetPosition(GetPosition() + move);

    SetWindowPosition(GetPosition().x, GetPosition().y);
}
