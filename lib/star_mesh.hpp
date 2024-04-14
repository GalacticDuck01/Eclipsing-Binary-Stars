#pragma once

#include <math.h>
#include <SFML/Graphics.hpp>

class StarMesh {
    public:
        StarMesh(int recursionLevel);
        ~StarMesh();
        void Draw(sf::RenderWindow& window, sf::Vector3f positionOffset, float radius);
    private:
        int recursionLevel;
        int numOfVertices;
        std::vector<sf::Vector3f> vertices;

        struct FaceIndices {
            int index0;
            int index1;
            int index2;

            FaceIndices(int index0, int index1, int index2) {
                this->index0 = index0;
                this->index1 = index1;
                this->index2 = index2;
            }
        };

        std::vector<FaceIndices> faces;

        void ProjectToUnitSphere();
        void AddTriangle(std::vector<FaceIndices>& facesList, int index0, int index1, int index2);
        int GetMidpointOfVertices(int index1, int index2);
        sf::Vector3f GetOffsettedPosition(sf::Vector3f positionOffset, float radius, int index);

};