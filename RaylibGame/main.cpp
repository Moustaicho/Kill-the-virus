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
    srand((unsigned int)time(NULL));
    //---------------Instatiate game------------------
    Engine* gameEngine = Engine::GetInstance();
    //--------------Add Textures here-----------------
    TextureHolder::GetInstance()->AddTexture("mask", LoadTexture("Assets/Shaders/mask.png"));
    TextureHolder::GetInstance()->AddTexture("plasma", LoadTexture("Assets/Shaders/plasma.png"));
    TextureHolder::GetInstance()->AddTexture("cursor", LoadTexture("Assets/Sprites/Cursor.png"));
    gameEngine->SetCustomCursor(TextureHolder::GetInstance()->GetTexture("cursor"));
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

    Player player;
    gameScene->AddGameObject(&player);

    GameUI gameUI(&game);
    gameScene->AddGameObject(&gameUI);

    //--------------Initialize game------------------
    gameEngine->Initialize();
    //----------------Update game--------------------
    gameEngine->Update();
    
    return 0;
}
/*
#include "rlgl.h"
Texture2D GridTexture;
void DrawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color)
{
    float x = position.x;
    float y = position.y;
    float z = position.z;

    // Set desired texture to be enabled while drawing following vertex data
    rlSetTexture(texture.id);

    // Vertex data transformation can be defined with the commented lines,
    // but in this example we calculate the transformed vertex data directly when calling rlVertex3f()
    //rlPushMatrix();
        // NOTE: Transformation is applied in inverse order (scale -> rotate -> translate)
        //rlTranslatef(2.0f, 0.0f, 0.0f);
        //rlRotatef(45, 0, 1, 0);
        //rlScalef(2.0f, 2.0f, 2.0f);

    rlBegin(RL_QUADS);
    rlColor4ub(color.r, color.g, color.b, color.a);
    // Front Face
    rlNormal3f(0.0f, 0.0f, 1.0f);       // Normal Pointing Towards Viewer
    rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width / 2, y - height / 2, z + length / 2);  // Bottom Left Of The Texture and Quad
    rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width / 2, y - height / 2, z + length / 2);  // Bottom Right Of The Texture and Quad
    rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width / 2, y + height / 2, z + length / 2);  // Top Right Of The Texture and Quad
    rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width / 2, y + height / 2, z + length / 2);  // Top Left Of The Texture and Quad
    // Back Face
    rlNormal3f(0.0f, 0.0f, -1.0f);     // Normal Pointing Away From Viewer
    rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width / 2, y - height / 2, z - length / 2);  // Bottom Right Of The Texture and Quad
    rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width / 2, y + height / 2, z - length / 2);  // Top Right Of The Texture and Quad
    rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width / 2, y + height / 2, z - length / 2);  // Top Left Of The Texture and Quad
    rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width / 2, y - height / 2, z - length / 2);  // Bottom Left Of The Texture and Quad
    // Top Face
    rlNormal3f(0.0f, 1.0f, 0.0f);       // Normal Pointing Up
    rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width / 2, y + height / 2, z - length / 2);  // Top Left Of The Texture and Quad
    rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width / 2, y + height / 2, z + length / 2);  // Bottom Left Of The Texture and Quad
    rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width / 2, y + height / 2, z + length / 2);  // Bottom Right Of The Texture and Quad
    rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width / 2, y + height / 2, z - length / 2);  // Top Right Of The Texture and Quad
    // Bottom Face
    rlNormal3f(0.0f, -1.0f, 0.0f);     // Normal Pointing Down
    rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width / 2, y - height / 2, z - length / 2);  // Top Right Of The Texture and Quad
    rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width / 2, y - height / 2, z - length / 2);  // Top Left Of The Texture and Quad
    rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width / 2, y - height / 2, z + length / 2);  // Bottom Left Of The Texture and Quad
    rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width / 2, y - height / 2, z + length / 2);  // Bottom Right Of The Texture and Quad
    // Right face
    rlNormal3f(1.0f, 0.0f, 0.0f);       // Normal Pointing Right
    rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width / 2, y - height / 2, z - length / 2);  // Bottom Right Of The Texture and Quad
    rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width / 2, y + height / 2, z - length / 2);  // Top Right Of The Texture and Quad
    rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width / 2, y + height / 2, z + length / 2);  // Top Left Of The Texture and Quad
    rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width / 2, y - height / 2, z + length / 2);  // Bottom Left Of The Texture and Quad
    // Left Face
    rlNormal3f(-1.0f, 0.0f, 0.0f);    // Normal Pointing Left
    rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width / 2, y - height / 2, z - length / 2);  // Bottom Left Of The Texture and Quad
    rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width / 2, y - height / 2, z + length / 2);  // Bottom Right Of The Texture and Quad
    rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width / 2, y + height / 2, z + length / 2);  // Top Right Of The Texture and Quad
    rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width / 2, y + height / 2, z - length / 2);  // Top Left Of The Texture and Quad
    rlEnd();
    //rlPopMatrix();

    rlSetTexture(0);
}
void DrawScene()
{
    // grid of cube trees on a plane to make a "world"
    DrawPlane(Vector3 { 0, 0, 0 }, Vector2 { 50, 50 }, BEIGE); // simple world plane
    float spacing = 4;
    int count = 5;

    for (float x = -count * spacing; x <= count * spacing; x += spacing)
    {
        for (float z = -count * spacing; z <= count * spacing; z += spacing)
        {
            Vector3 pos = { x, 0.5f, z };

            Vector3 min = { x - 0.5f,0,z - 0.5f };
            Vector3 max = { x + 0.5f,1,z + 0.5f };

            DrawCubeTexture(GridTexture, Vector3 { x, 1.5f, z }, 1, 1, 1, GREEN);
            DrawCubeTexture(GridTexture, Vector3 { x, 0.5f, z }, 0.25f, 1, 0.25f, BROWN);
        }
    }

    DrawCube(Vector3 { 2, 1, 0 }, 1, 1, 1, RED);
    DrawCube(Vector3 { 0, 1, 2 }, 1, 1, 1, BLUE);
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - split screen");

    Image img = GenImageChecked(256, 256, 32, 32, DARKGRAY, WHITE);
    GridTexture = LoadTextureFromImage(img);
    UnloadImage(img);
    SetTextureFilter(GridTexture, TEXTURE_FILTER_ANISOTROPIC_16X);
    SetTextureWrap(GridTexture, TEXTURE_WRAP_CLAMP);

    Camera player1Camera = { 0 };
    player1Camera.fovy = 45;
    player1Camera.up.y = 1;
    player1Camera.target.y = 1;
    player1Camera.position.z = -3;
    player1Camera.position.y = 1;

    Camera player2Camera = { 0 };
    player2Camera.fovy = 45;
    player2Camera.up.y = 1;
    player2Camera.target.y = 3;
    player2Camera.position.x = -3;
    player2Camera.position.y = 3;

    RenderTexture player1Screen = LoadRenderTexture(screenWidth / 2, screenHeight);
    RenderTexture player2Screen = LoadRenderTexture(screenWidth / 2, screenHeight);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    Rectangle splitScreenRect = { 0,0,player1Screen.texture.width,-player1Screen.texture.height };

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // draw player 1's view
        BeginTextureMode(player1Screen);
        ClearBackground(SKYBLUE);
        BeginMode3D(player1Camera);
        DrawScene();
        EndMode3D();
        EndTextureMode();

        // draw player 2's view
        BeginTextureMode(player2Screen);
        ClearBackground(LIGHTGRAY);
        BeginMode3D(player2Camera);
        DrawScene();
        EndMode3D();
        EndTextureMode();

        // draw the textures to the screen
        BeginDrawing();
        ClearBackground(BLACK);

        DrawTextureRec(player1Screen.texture, splitScreenRect, Vector2 { 0, 0 }, WHITE);
        DrawTextureRec(player2Screen.texture, splitScreenRect, Vector2 { screenWidth / 2, 0 }, WHITE);
        EndDrawing();
    }

    UnloadRenderTexture(player1Screen);
    UnloadRenderTexture(player2Screen);
    UnloadTexture(GridTexture);

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
*/