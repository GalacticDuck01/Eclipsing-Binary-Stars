#pragma once

#include <stdio.h>
#include <SFML/Graphics.hpp>

#include <star.hpp>

class Simulation {
    public:
        std::vector<Star> stars;

        Simulation();
        ~Simulation();
        void Draw(sf::RenderWindow& window);
        void Update();
        void HandleInput(sf::Event& event);
    private:

};