#pragma once

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class Star {
    public:
        std::vector<sf::CircleShape> surfaces;

        Star();
        ~Star();
        void Draw(sf::RenderWindow& window);
    private:
};