#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>

#include <star.hpp>
#include <physics.hpp>

class Simulation {
    public:
        std::vector<Star> stars;

        Simulation();
        ~Simulation();
        void Draw(sf::Vector2f originPosition);
        void Update(float deltaTime);
        void HandleInput();
    private:
        float eccentricity;
        float totalSeparation;
        float orbitalPeriod;
};