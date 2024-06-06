#pragma once

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <raylib.hpp>

#include <star_mesh.hpp>

class Star {
    public:
        Vector3 position;
        float radius;
        float theta;
        float phi;

        Star(int recursionLevel);
        ~Star();
        void Draw();
        void Update();
        void RotateAroundXAxis(float angle);
        void RotateAroundYAxis(float angle);
    private:
        StarMesh starMesh;
};