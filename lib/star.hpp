#pragma once

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>

#include <star_face.hpp>

class Star {
    public:
        sf::Vector3f position;
        float radius;
        int recursionLevel;
        std::vector<sf::Vector3f> vertices;
        std::vector<StarFace> faces;

        Star();
        ~Star();
        void Draw(sf::RenderWindow& window);
    private:
        int numOfVertices;

        void ProjectToUnitSphere();
        void AddTriangle(std::vector<StarFace>& facesList, int index0, int index1, int index2);
        int GetMidpointOfVertices(int point1, int point2);
        sf::Vector3f GetOverallPosition(int index);
};