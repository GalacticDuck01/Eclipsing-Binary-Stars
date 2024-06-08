#include <physics.hpp>

Physics::Physics() {}
Physics::~Physics() {}

Vector3 Physics::GetPosition(float a, float e, float theta) {
    float r = a*(1 - pow(e, 2)) / (1 + e*cos(theta));
    float x = r*cos(theta);
    float y = r*sin(theta);
    return Vector3{x, y, 0};
}

float Physics::GetOrbitalPeriod(float a, float m1, float m2) {
    float G = 6.67*pow(10, -11);
    return sqrt((4*pow(M_PI, 2)*pow(a, 3))/(G*(m1+m2)));
}

float Physics::GetDeltaTheta(float P, float a, Vector3 r, float e, float dt) {
    float rMag = sqrt(pow(r.x, 2) + pow(r.y, 2) + pow(r.z, 2));
    return 2*M_PI/P*pow(a/rMag, 2)*sqrt(1-pow(e, 2))*dt;
}
