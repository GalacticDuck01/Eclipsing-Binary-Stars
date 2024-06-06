#include <simulation.hpp>

Simulation::Simulation() {
    Star star = Star(3);
    stars.push_back(star);
}

Simulation::~Simulation() {

}

/*!
    Draws the simulation to the screen.
    @param window: Reference to the window.
*/
void Simulation::Draw() {
    for (auto& star: stars) {
        star.Draw();
    }
    
}

void Simulation::Update() {
    for (auto& star: stars) {
        star.Update();
    }
}

void Simulation::HandleInput() {
    float angle = 0.01*M_PI/180.f;

    float angleX = 0.f;
    float angleY = 0.f;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
        angleY += angle;
    }
    else if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
        angleY -= angle;
    }
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
        angleX -= angle;
    }
    else if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
        angleX += angle;
    }

    if (angleX != 0.f) {
        for (auto& star: stars) {
            star.RotateAroundXAxis(angleX);
        }
    }
    if (angleY != 0.f) {
        for (auto& star: stars) {
            star.RotateAroundYAxis(angleY);
        }
    }
}
