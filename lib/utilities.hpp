#pragma once

#include <raylib.hpp>
#include <math.h>

class Utilities {
    public:
        static Vector3 RotateAroundY(float angle, Vector3& vector);
        static Vector3 RotateAroundX(float angle, Vector3& vector);
    private:
        struct Matrix {
            float a11; float a12; float a13;
            float a21; float a22; float a23;
            float a31; float a32; float a33;

            Matrix(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33){
                this->a11 = a11;
                this->a12 = a12;
                this->a13 = a13;
                this->a21 = a21;
                this->a22 = a22;
                this->a23 = a23;
                this->a31 = a31;
                this->a32 = a32;
                this->a33 = a33;
            }
        };

        static Vector3 DotProduct(Matrix matrix, Vector3& vector);
    
};