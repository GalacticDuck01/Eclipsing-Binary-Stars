#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class FpsTracker {
    public:
        FpsTracker();
        ~FpsTracker();
        void Update();
    private:
        sf::Clock clock;
        unsigned int noFrames;
        unsigned int fps;

        int GetFPS();
};