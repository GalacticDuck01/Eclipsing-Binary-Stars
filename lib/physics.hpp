#pragma once

#include <math.h>
#include <raylib.hpp>
#include <raymath.hpp>

class Physics {
    public:
        Physics();
        ~Physics();

        static Vector3 GetPosition(float a, float e, float theta);
        static float GetOrbitalPeriod(float a, float m1, float m2);
        static float GetDeltaTheta(float P, float a, Vector3 r, float e, float dt);
};