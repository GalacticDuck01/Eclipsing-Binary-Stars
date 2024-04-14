#pragma once

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>

#include <star_face.hpp>
#include <star_mesh.hpp>

class Star {
    public:
        sf::Vector3f position;
        float radius;

        Star(int recursionLevel);
        ~Star();
        void Draw(sf::RenderWindow& window);
    private:
        StarMesh starMesh;
};