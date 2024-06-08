#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include <raylib.hpp>
#include <raymath.hpp>

#include <utilities.hpp>

/*!
    A mesh of triangles representing a star's spherical surface.
    The methods here are adapted from http://blog.andreaskahler.com/2009/06/creating-icosphere-mesh-in-code.html.
*/
class StarMesh {
    public:
        StarMesh(int recursionLevel, Color colour);
        ~StarMesh();
        void Draw(Vector3 positionOffset, float radius);
        void Update(float theta, float phi);
        void RotateAroundXAxis(float angle);
        void RotateAroundYAxis(float angle);
    private:
        int recursionLevel;
        Color colour;
        int numOfVertices;
        std::vector<Vector3> vertices;
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
        Vector3 GetOffsettedPosition(Vector3 positionOffset, float radius, int index);

};