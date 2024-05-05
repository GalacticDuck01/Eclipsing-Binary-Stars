#pragma once

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>

#include <star_mesh.hpp>

class Star {
    public:
        sf::Vector3f position;
        float radius;
        float theta;
        float phi;

        Star(int recursionLevel);
        ~Star();
        void Draw(sf::RenderWindow& window);
        void Update();
        void RotateAroundXAxis(float angle);
        void RotateAroundYAxis(float angle);
    private:
        StarMesh starMesh;
};