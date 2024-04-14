#pragma once

#include <math.h>
#include <SFML/Graphics.hpp>

#include <star_face.hpp>

class StarMesh {
    public:
        StarMesh(int recursionLevel);
        ~StarMesh();
        void Draw(sf::RenderWindow& window, sf::Vector3f positionOffset, float radius);
    private:
        int recursionLevel;
        int numOfVertices;
        std::vector<sf::Vector3f> vertices;
        std::vector<StarFace> faces;

        void ProjectToUnitSphere();
        void AddTriangle(std::vector<StarFace>& facesList, int index0, int index1, int index2);
        int GetMidpointOfVertices(int index1, int index2);
        sf::Vector3f GetOffsettedPosition(sf::Vector3f positionOffset, float radius, int index);

};