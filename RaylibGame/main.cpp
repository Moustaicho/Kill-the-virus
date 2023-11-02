#include "raylib.h"
#include <string>
#include <iostream>


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "KILL THE VIRUS - MAIN WINDOW");
    InitWindow(screenWidth, screenHeight, "MENU WINDOW");
    Vector2 screenPos{GetMonitorWidth(0), GetMonitorHeight(0)};
    SetWindowPosition(screenPos.x/2 - screenWidth/2, screenPos.y/2 - screenHeight/2);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    bool isMoving = false;
    float speed = 10.0f;
    float upspeed = 10.0f;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_ENTER))
        {
            isMoving = !isMoving;
        }

        if (isMoving)
        {
            if (GetWindowPosition().x + screenWidth >= GetMonitorWidth(0)) 
            {
                speed *= -1;
            }
            else if (GetWindowPosition().x <= 0) 
            {
                speed *= -1;
            }

            if (GetWindowPosition().y + screenHeight >= GetMonitorHeight(0))
            {
                upspeed *=-1;
            }
            else if (GetWindowPosition().y <= 0)
            {
                upspeed *= -1;
            }


            SetWindowPosition(GetWindowPosition().x + speed, GetWindowPosition().y + upspeed);

        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        DrawText(std::to_string(GetFPS()).c_str(), 10, 10, 20, GREEN);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}