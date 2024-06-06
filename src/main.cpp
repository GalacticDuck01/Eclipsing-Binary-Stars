#include <raylib.hpp>

#include <simulation.hpp>

int main()
{
    int screenWidth = 1080;
    int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "Star Simulator");
    InitAudioDevice();

    Simulation simulation = Simulation();

    while (!WindowShouldClose()) {
        simulation.HandleInput();

        simulation.Update();

        BeginDrawing();

        ClearBackground(BLACK);

        simulation.Draw();
        DrawText(TextFormat("FPS: %i", GetFPS()), 200, 0, 20, WHITE);
        // DrawText(TextFormat("%0.f, %0.f", GetMousePosition().x, GetMousePosition().y), screenWidth - 200.f, 0, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    CloseAudioDevice();

    return 0;
}