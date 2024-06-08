#include <physics.hpp>

Physics::Physics() {}
Physics::~Physics() {}

/*!
    Calculates the position of an object in a two-dimensional orbit given its semi-major axis, eccentricity, and true anomaly.

    @param a Semi-major axis of the orbit.
    @param e Eccentricity of the orbit.
    @param trueAnomaly True anomaly of the object, in radians.

    @return Position of the object.
*/
Vector3 Physics::GetPosition(float a, float e, float trueAnomaly) {
    float r = a*(1 - pow(e, 2)) / (1 + e*cos(trueAnomaly));
    float x = r*cos(trueAnomaly);
    float y = r*sin(trueAnomaly);
    return Vector3{x, y, 0};
}

/*!
    Calculates the orbital period of an object in a two-dimensional orbit.

    @param a Semi-major axis of the orbit.
    @param m1 Mass of the primary object.
    @param m2 Mass of the secondary object.

    @return Orbital period of the object.
*/
float Physics::GetOrbitalPeriod(float a, float m1, float m2) {
    float G = 6.67*pow(10, -11);
    return sqrt((4*pow(M_PI, 2)*pow(a, 3))/(G*(m1+m2)));
}

/*!
    Calculates the change in theta (angular velocity) for an object in an elliptical orbit.

    @param P Orbital period of the object.
    @param a Semi-major axis of the orbit.
    @param r Position of the object.
    @param e Eccentricity of the orbit.
    @param dt Time step.

    @return Change in theta.
*/
float Physics::GetDeltaTheta(float P, float a, Vector3 r, float e, float dt) {
    float rMag = sqrt(pow(r.x, 2) + pow(r.y, 2) + pow(r.z, 2));
    return 2*M_PI/P*pow(a/rMag, 2)*sqrt(1-pow(e, 2))*dt;
}
