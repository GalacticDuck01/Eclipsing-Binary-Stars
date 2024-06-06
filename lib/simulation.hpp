#pragma once

#include <stdio.h>
#include <raylib.hpp>

#include <star.hpp>

class Simulation {
    public:
        std::vector<Star> stars;

        Simulation();
        ~Simulation();
        void Draw();
        void Update();
        void HandleInput();
    private:

};