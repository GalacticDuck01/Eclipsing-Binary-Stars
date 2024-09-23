#pragma once

#include <math.h>
#include <SFML/System/Vector3.hpp>

class Physics {
    public:
        Physics();
        ~Physics();

        static sf::Vector3f GetPosition(float a, float e, float theta);
        static float GetOrbitalPeriod(float a, float m1, float m2);
        static float GetDeltaTheta(float P, float a, sf::Vector3f r, float e, float dt);
};