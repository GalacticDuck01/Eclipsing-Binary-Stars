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

        simulation.Update(GetFrameTime());

        BeginDrawing();

        ClearBackground(BLACK);

        simulation.Draw(Vector2{(float)screenWidth/2, (float)screenHeight/2});
        DrawText(TextFormat("FPS: %i", GetFPS()), 200, 0, 20, WHITE);
        // DrawText(TextFormat("%0.f, %0.f", GetMousePosition().x, GetMousePosition().y), screenWidth - 200.f, 0, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    CloseAudioDevice();

    return 0;
}