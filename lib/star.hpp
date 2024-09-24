#pragma once

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>

#include <star_mesh.hpp>
#include <physics.hpp>

class Star {
    public:
        sf::Vector3f position;
        float mass;
        float radius;
        float semiMajorAxis;
        float trueAnomaly;
        float theta;
        float phi;
        sf::Color colour;

        Star(sf::Vector3f position, float mass, float radius, float semiMajorAxis, int recursionLevel, sf::Color colour);
        ~Star();
        void Draw(sf::Vector2f originPosition);
        void Update(sf::Vector3f newPosition);
        void RotateAroundXAxis(float angle);
        void RotateAroundYAxis(float angle);
    private:
        StarMesh starMesh;
};