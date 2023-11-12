#include "Engine.h"
#include "FontLibrary.h"
#include "Menu.h"
#include "Game.h"
#include "Credit.h"
#include "GameUI.h"
#include "Player.h"
#include "raymath.h"
#if defined(PLATFORM_DESKTOP)
#define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB
#define GLSL_VERSION            100
#endif
//X is Right
//Y is Up
//Z is Forward
int main(void)
{
    //---------------Instatiate game------------------
    Engine* gameEngine = Engine::GetInstance();

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