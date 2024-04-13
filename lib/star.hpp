#pragma once

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class Star {
    public:
        sf::Vector3f position;
        float radius;
        std::vector<sf::Vector3f> vertices;
        std::vector<sf::ConvexShape> triangles;

        Star();
        ~Star();
        void Draw(sf::RenderWindow& window);
    private:
        void ProjectToUnitSphere();
        void AddTriangle(sf::Vector3f vertex1, sf::Vector3f vertex2, sf::Vector3f vertex3);
};