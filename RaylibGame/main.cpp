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

//3D Space
//X is Right
//Y is Up
//Z is Forward

#if _DEBUG 
int main(void)
#else
int WinMain(void)
#endif
{
    srand((unsigned int)time(NULL)); //Need this for random numbers
    //---------------Instatiate game------------------
    Engine* gameEngine = Engine::GetInstance();

    //-------------Application Setup------------------
    Image icon = LoadImage("Assets/Sprites/plasma.png");
    SetWindowIcon(icon);

    //--------------Add Textures here-----------------
    Texture2D* mask = new Texture2D(LoadTexture("Assets/Sprites/mask.png"));
    Texture2D* plasma = new Texture2D(LoadTexture("Assets/Sprites/plasma.png"));
    Texture2D* cursor = new Texture2D(LoadTexture("Assets/Sprites/Cursor.png"));
    RenderTexture2D* rTexture = new RenderTexture2D(LoadRenderTexture(50, 50));

    TextureHolder::GetInstance()->AddTexture("mask", mask);
    TextureHolder::GetInstance()->AddTexture("plasma", plasma);
    TextureHolder::GetInstance()->AddTexture("cursor", cursor);
    TextureHolder::GetInstance()->AddRenderTexture("RT_Virus", rTexture);
    gameEngine->SetCustomCursor(TextureHolder::GetInstance()->GetTexture("cursor"));

    //----------------Add Shader here-----------------
    Shader* shader = new Shader(LoadShader(TextFormat("Assets/Shaders/S_Virus.vs", GLSL_VERSION), TextFormat("Assets/Shaders/S_Virus.fs", GLSL_VERSION)));
    ShaderHolder::GetInstance()->AddShader("S_Virus", shader);
    
    //----------------Add Music here------------------
    Music* mGame = new Music(LoadMusicStream("Assets/Audio/Music/Octahedron - CAMERA_SURVEILLANCE.wav"));
    Music* mGameOver = new Music(LoadMusicStream("Assets/Audio/Music/Octahedron - The Virus Manifests.wav"));
    MusicHolder::GetInstance()->AddMusic("M_Game", mGame);
    MusicHolder::GetInstance()->AddMusic("M_GameOver", mGameOver);
    //----------------Add Fonts here------------------
    Font* font = new Font(LoadFont("Assets/Font/monofonto.otf"));
    FontLibrary::GetInstance()->AddFont("Monto", font);
    
    //-----------Add Models & Mesh here---------------
    Mesh* vMesh = new Mesh(GenMeshSphere(1, 16, 16));
    Model* vModel = new Model(LoadModelFromMesh(*vMesh));
    ModelHolder::GetInstance()->AddMesh("Mesh_Virus", vMesh);
    ModelHolder::GetInstance()->AddModel("Model_Virus", vModel);
    
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

    GameUI gameUI(&game);
    gameScene->AddGameObject(&gameUI);
    Player player;
    player.SetGameRef(&game);
    player.SetGameUIRef(&gameUI);
    player.SetScoreRef(&score);
    game.SetPlayerRef(&player);
    gameScene->AddGameObject(&player);
    tutorialScene->AddGameObject(&player);
    
    //--------------Initialize game------------------
    gameEngine->Initialize();
    //----------------Update game--------------------
    gameEngine->Update();
    
    return 0;
}