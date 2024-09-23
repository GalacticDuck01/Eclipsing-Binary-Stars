#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector3.hpp>

#include <maths/linear_algebra.hpp>
#include <renderer/renderer.hpp>

/*!
    A mesh of triangles representing a star's spherical surface.
    The methods here are adapted from http://blog.andreaskahler.com/2009/06/creating-icosphere-mesh-in-code.html.
*/
class StarMesh {
    public:
        StarMesh(int recursionLevel, sf::Color colour);
        ~StarMesh();
        void Draw(sf::Vector3f positionOffset, float radius);
        void Update(float theta, float phi);
        void RotateAroundXAxis(float angle);
        void RotateAroundYAxis(float angle);
    private:
        int recursionLevel;
        sf::Color colour;
        int numOfVertices;
        std::vector<sf::Vector3f> vertices;
        float currentTheta;
        float currentPhi;

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