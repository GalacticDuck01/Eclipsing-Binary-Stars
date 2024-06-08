#pragma once

#include <stdio.h>
#include <raylib.hpp>

#include <star.hpp>
#include <physics.hpp>

class Simulation {
    public:
        std::vector<Star> stars;

        Simulation();
        ~Simulation();
        void Draw(Vector2 originPosition);
        void Update(float deltaTime);
        void HandleInput();
    private:
        float eccentricity;
        float totalSeparation;
        float orbitalPeriod;
};