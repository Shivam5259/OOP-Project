#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>
#include "C:\raylib\raylib\src\raylib.h"
#include "Bank.h"
#include "Account.h"
#include "AccountHolder.h"
#include "Admin.h"
#include "User.h"
#include "Card.h"

void splashScreen()
{
    bool startAnimation = false;
    int titleY = 250;
    int targetY = 50;
    bool onSplashScreen = true;
    float animationSpeed = 4.0f;

    while (onSplashScreen && !WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(SKYBLUE);
        DrawText("My Bank", 300, titleY, 50, DARKBLUE);

        if (IsKeyPressed(KEY_ENTER))
        {
            startAnimation = true;
        }

        if (startAnimation)
        {
            if (titleY > targetY)
            {
                titleY -= animationSpeed;
            }
            else
            {
                onSplashScreen = false;
            }
        }
        EndDrawing();
    }
    
    return;
}

using namespace std;

int main()
{
    Bank b;

    InitWindow(800, 600, "Banking System");
    SetTargetFPS(60);
    bool splash = true;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(SKYBLUE);
        if (splash)
        {
            splashScreen();
            splash = false;
        }
        else{
            b.drawInputWindow();
        }
        EndDrawing();
        
    }
    CloseWindow();
}