#include "Engine.h"
#include "FontLibrary.h"
#include "TextureHolder.h"
#include "Menu.h"
#include "Game.h"
#include "Credit.h"
#include "GameUI.h"
#include "Player.h"
#include "raymath.h"

//X is Right
//Y is Up
//Z is Forward
int main(void)
{
    //---------------Instatiate game------------------
    Engine* gameEngine = Engine::GetInstance();
    //--------------Add Textures here-----------------
    TextureHolder::GetInstance()->AddTexture("mask", LoadTexture("Assets/Shaders/mask.png"));
    TextureHolder::GetInstance()->AddTexture("plasma", LoadTexture("Assets/Shaders/plasma.png"));
    //----------------Add Fonts here------------------
    Font font = LoadFont("Assets/Font/monofonto.otf");
    FontLibrary* fontLibrary = FontLibrary::GetInstance();
    fontLibrary->AddFont("Monto", font);
    
    //-------------Add gameplay here------------------
    Scene* menuScene = new Scene("MenuScene");
    gameEngine->AddScene(menuScene);
    Scene* gameScene = new Scene("GameScene");
    gameEngine->AddScene(gameScene);
    Scene* creditScene = new Scene("CreditScene");
    gameEngine->AddScene(creditScene);

    Menu menu;
    menuScene->AddGameObject(&menu);
    Game game;
    gameScene->AddGameObject(&game);
    Credit credit;
    creditScene->AddGameObject(&credit);

    Player player(*gameEngine);
    gameScene->AddGameObject(&player);

    GameUI gameUI;
    gameScene->AddGameObject(&gameUI);

    //--------------Initialize game------------------
    gameEngine->Initialize();
    //----------------Update game--------------------
    gameEngine->Update();
    
    return 0;
}