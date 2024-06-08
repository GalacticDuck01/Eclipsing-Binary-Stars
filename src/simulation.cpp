#include <simulation.hpp>

Simulation::Simulation() {
    const float MASS_1 = 400.f;
    const float RADIUS_1 = 300.f;
    const float MASS_2 = 50.f;
    const float RADIUS_2 = 50.f;
    const float MASS_SUM = MASS_1 + MASS_2;

    this->totalSeparation = 400.f;
    this->eccentricity = 0.f;
    this->orbitalPeriod = Physics::GetOrbitalPeriod(totalSeparation, MASS_1, MASS_2)/pow(10, 7);

    float semiMajorAxis1 = (totalSeparation*MASS_2)/MASS_SUM;
    float semiMajorAxis2 = (totalSeparation*MASS_1)/MASS_SUM;

    Vector3 initPosStar1 = Physics::GetPosition(semiMajorAxis1, eccentricity, 0.f);
    Vector3 initPosStar2 = Physics::GetPosition(semiMajorAxis2, eccentricity, 0.f);

    Star star1(initPosStar1, MASS_1, RADIUS_1, semiMajorAxis1, 4, RED);
    stars.push_back(star1);

    Star star2(initPosStar2, MASS_2, RADIUS_2, -semiMajorAxis2, 2, BLUE);
    stars.push_back(star2);
}

Simulation::~Simulation() {

}

/*!
    Draws the simulation to the screen.
    @param window: Reference to the window.
*/
void Simulation::Draw(Vector2 originPosition) {
    for (auto& star: stars) {
        star.Draw(originPosition);
    }
}

void Simulation::Update(float deltaTime) {
    float deltaTheta = 0.f;
    Vector3 newPos;
    for (auto& star: stars) {
        deltaTheta = Physics::GetDeltaTheta(orbitalPeriod, star.semiMajorAxis, star.position, eccentricity, deltaTime);
        star.trueAnomaly += 10.f * deltaTheta;
        newPos = Physics::GetPosition(star.semiMajorAxis, eccentricity, star.trueAnomaly);
        star.Update(newPos);
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
