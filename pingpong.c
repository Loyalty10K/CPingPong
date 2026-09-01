#include "raylib.h"
#include <stdio.h>
#include <time.h>

int main() {
    int widthwindow = 1500;
    int heightwindow = 800;
    InitWindow(widthwindow, heightwindow, "First Game");
    SetTargetFPS(200);

    float a = 1400;
    float b = 350;
    float c = 100;
    float d = 350;
    float circlex = 750;
    float circley = 400;
    float speed = 3;
    int directionX = 1;
    int directionY = 1;

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_UP))    b -= 5;
        if (IsKeyDown(KEY_DOWN))  b += 5;
        if (IsKeyDown(KEY_W)) d -= 5;
        if (IsKeyDown(KEY_S)) d += 5;

        circlex += speed * directionX;
        circley += speed * directionY;
        if (circley <= 0 || circley >= heightwindow) {
            directionY = directionY * -1;
        }
        if (circlex <= 0 || circlex >= widthwindow) {
            directionX = directionX * -1;
        }
        if (circlex + 15 >= a && circlex <= a && circley >= b && circley <= b + 150) {
            directionX = directionX * -1;
        }
        if (circlex - 15 <= c + 30 && circlex >= c + 30 && circley >= d && circley <= d + 150) {
            directionX = directionX * -1;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(a, b, 30, 150, RED);
        DrawRectangle(0, 0, 15, 800, BLACK);
        DrawRectangle(1485, 0, 15, 800, BLACK);
        DrawRectangle(c, d, 30, 150, BLUE);
        DrawCircle(circlex, circley, 15, BLACK); 
        EndDrawing();
        
    }

    CloseWindow();
    return 0;
}
