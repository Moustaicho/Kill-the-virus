#include "Player.h"

Player::Player() : GameObject("Player")
    , engineRef(Engine::GetInstance())
    , move({0,0})
    , gameRef(nullptr)
    , gameUIRef(nullptr)
    , scoreRef(nullptr)
    , dmgTimer(1)
    , isMoving(false)
{
    
}

void Player::Start()
{
    speed = 300;
    score = 0;
    health = 100;
    healthGot = 3;
    hackSpeed = 120;
    gameUIRef->SetPlayerHealth(health);
    if (gameRef != nullptr)
    {
        gameUIRef->SetScore(score);
    }

    SetPosition({ GetMonitorWidth(engineRef->GetCurrentMonitor()) / 2 - engineRef->GetWindow()->GetSize().x / 2.0f, GetMonitorHeight(engineRef->GetCurrentMonitor()) / 2 - engineRef->GetWindow()->GetSize().y / 2.0f});
}

void Player::Update()
{
    if (IsKeyPressed(KEY_F2))
    {
        if (GetMasterVolume() - 0.1f <= 0)
        {
            SetMasterVolume(0.0f);
        }
        else
        {
            SetMasterVolume(GetMasterVolume() - 0.1f);
        }
    }
    if (IsKeyPressed(KEY_F3))
    {
        if (GetMasterVolume() + 0.1f >= 1)
        {
            SetMasterVolume(1.0f);
        }
        else
        {
            SetMasterVolume(GetMasterVolume() + 0.1f);
        }
       
    }

    if (IsKeyDown(KEY_SPACE))
    {
        for (Virus* virus : gameRef->GetVirus())
        {
            if (CheckCollisionCircles({255,255}, 100, virus->GetPosition(), 20))
            {
                gameUIRef->SetHackUIState(true);
                StartHacking(virus);
                break;
            }
        }
    }
    else
    {
        gameUIRef->SetHackUIState(false);
    }

    move = { 0, 0 };
    if (IsKeyDown(KEY_A))
    {
        move.x = -speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_D))
    {
        move.x = speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_W))
    {
        move.y = -speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_S))
    {
        move.y = speed * GetFrameTime();
    }
    MoveScreen();
}

void Player::Draw()
{
   
}

void Player::End()
{
    scoreRef->SetResult(score);
}

void Player::SetGameRef(Game* game)
{
    gameRef = game;
}

void Player::SetGameUIRef(GameUI* gameUI)
{
    gameUIRef = gameUI;
}

void Player::SetScoreRef(Score* score)
{
    scoreRef = score;
}

void Player::Damage(int dmg)
{
    health -= dmg;
    gameUIRef->SetPlayerHealth(health);
    if (health <= 0)
    {
        scoreRef->SetResult(score);
        engineRef->LoadScene("ScoreScene");
    }
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

void Player::StartHacking(Virus* virus)
{
    gameUIRef->SetVirusName(virus->GetName());
    dmgTimer -= hackSpeed * GetFrameTime();
    if (dmgTimer <= 0)
    {
        virus->Damage(1);
        dmgTimer = 1;
    }

    gameUIRef->SetVirusHealth(virus->GetHealth());

    if (virus->GetHealth() <= 0)
    {
        hackSpeed += 80;
        speed+=5;
        gameRef->RemoveVirus(virus);
        gameUIRef->SetHackUIState(false);
        score += 100;
        gameUIRef->SetScore(score);
        health += std::floor(sqrt(healthGot));
        healthGot += 1;
        if (health >= 100)
        {
            health = 100;
        }
        gameUIRef->SetPlayerHealth(health);
    }
}
