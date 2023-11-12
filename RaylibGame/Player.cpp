#include "Player.h"

Player::Player(Engine& ref) : GameObject("Player")
    , gameref(ref)
    , move({0,0})
{
    
}

void Player::Start()
{
    center = { gameref.GetWindow()->GetSize().x / 2.0f, gameref.GetWindow()->GetSize().y / 2.0f };
    SetPosition({ (float)GetMonitorWidth(gameref.GetCurrentMonitor()) / 2.0f - center.x, (float)GetMonitorHeight(gameref.GetCurrentMonitor())/2.0f - center.y });
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

    currentRadius+= detectorSpeed;
    if (currentRadius >= 200)
    {
        currentRadius = 10;
    }

    MoveScreen();
}

void Player::Draw()
{
    DrawCircle(center.x, center.y, 200, { 0, 64, 24, 255 });
    DrawCircleLines(center.x, center.y, 200, WHITE);
    DrawCircleLines(center.x, center.y, 150, WHITE);
    DrawCircleLines(center.x, center.y, 100, WHITE);
    DrawCircleLines(center.x, center.y, 50, WHITE);
    DrawRing({ center.x, center.y }, currentRadius-5, currentRadius, 0, 360, 24, {0, 255, 0, 255});
}

void Player::MoveScreen()
{
    SetPosition(GetPosition() + move);

    if (GetWindowPosition().x + gameref.GetWindow()->GetSize().x == GetMonitorWidth(0))
    {
        //SetPosition(GetPosition() - move);
    }
    else if (GetWindowPosition().x <= 0)
    {

    }

    if (GetWindowPosition().y + gameref.GetWindow()->GetSize().y == GetMonitorHeight(0))
    {

    }
    else if (GetWindowPosition().y <= 0)
    {

    }

    

    SetWindowPosition(GetPosition().x, GetPosition().y);
}
