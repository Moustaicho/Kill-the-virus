#include "Engine.h"
#include "FontLibrary.h"
#include "TextureHolder.h"
#include "ShaderHolder.h"
#include "MusicHolder.h"
#include "ModelHolder.h"
#include "Menu.h"
#include "Game.h"
#include "Credit.h"
#include "GameUI.h"
#include "Player.h"
#include "Tutorial.h"
#include "Score.h"
#include "raymath.h"

//X is Right
//Y is Up
//Z is Forward
int main(void)
{
    
    srand((unsigned int)time(NULL)); //Need this for random numbers
    //---------------Instatiate game------------------
    Engine* gameEngine = Engine::GetInstance();
    //--------------Add Textures here-----------------
    TextureHolder::GetInstance()->AddTexture("mask", LoadTexture("Assets/Sprites/mask.png"));
    TextureHolder::GetInstance()->AddTexture("plasma", LoadTexture("Assets/Sprites/plasma.png"));
    TextureHolder::GetInstance()->AddTexture("cursor", LoadTexture("Assets/Sprites/Cursor.png"));
    TextureHolder::GetInstance()->AddRenderTexture("RT_Virus", LoadRenderTexture(50, 50));
    gameEngine->SetCustomCursor(*TextureHolder::GetInstance()->GetTexture("cursor"));
    //----------------Add Shader here-----------------
    ShaderHolder::GetInstance()->AddShader("S_Virus", LoadShader(TextFormat("Assets/Shaders/S_Virus.vs", GLSL_VERSION), TextFormat("Assets/Shaders/S_Virus.fs", GLSL_VERSION)));
    //----------------Add Music here------------------
    MusicHolder::GetInstance()->AddMusic("M_Game", LoadMusicStream("Assets/Audio/Music/Octahedron - CAMERA_SURVEILLANCE.wav"));
    MusicHolder::GetInstance()->AddMusic("M_GameOver", LoadMusicStream("Assets/Audio/Music/Octahedron - The Virus Manifests.wav"));
    //----------------Add Fonts here------------------
    Font font = LoadFont("Assets/Font/monofonto.otf");
    FontLibrary* fontLibrary = FontLibrary::GetInstance();
    fontLibrary->AddFont("Monto", font);
    //-----------Add Models & Mesh here---------------
    ModelHolder::GetInstance()->AddMesh("Mesh_Virus", GenMeshSphere(1, 16, 16));
    ModelHolder::GetInstance()->AddModel("Model_Virus", LoadModelFromMesh(*ModelHolder::GetInstance()->GetMesh("Mesh_Virus")));
    //-------------Add gameplay here------------------
    Scene* menuScene = new Scene("MenuScene");
    gameEngine->AddScene(menuScene);
    Scene* gameScene = new Scene("GameScene");
    gameEngine->AddScene(gameScene);
    Scene* creditScene = new Scene("CreditScene");
    gameEngine->AddScene(creditScene);
    Scene* tutorialScene = new Scene("TutorialScene");
    gameEngine->AddScene(tutorialScene);
    Scene* scoreScene = new Scene("ScoreScene");
    gameEngine->AddScene(scoreScene);

    Menu menu;
    menuScene->AddGameObject(&menu);
    Game game;
    gameScene->AddGameObject(&game);
    Credit credit;
    creditScene->AddGameObject(&credit);
    Tutorial tutorial;
    tutorialScene->AddGameObject(&tutorial);
    Score score;
    scoreScene->AddGameObject(&score);

    Player player;
    gameScene->AddGameObject(&player);
    tutorialScene->AddGameObject(&player);

    GameUI gameUI(&game);
    gameScene->AddGameObject(&gameUI);

    //--------------Initialize game------------------
    gameEngine->Initialize();
    //----------------Update game--------------------
    gameEngine->Update();
    
    return 0;
}