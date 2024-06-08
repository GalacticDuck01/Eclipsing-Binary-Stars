#pragma once

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <raylib.hpp>

#include <star_mesh.hpp>
#include <physics.hpp>

class Star {
    public:
        Vector3 position;
        float mass;
        float radius;
        float semiMajorAxis;
        float systemTheta;
        float systemPhi;
        float theta;
        float phi;
        Color colour;

        Star(Vector3 position, float mass, float radius, float semiMajorAxis, int recursionLevel, Color colour);
        ~Star();
        void Draw(Vector2 originPosition);
        void Update(Vector3 newPosition);
        void RotateAroundXAxis(float angle);
        void RotateAroundYAxis(float angle);
    private:
        StarMesh starMesh;
};