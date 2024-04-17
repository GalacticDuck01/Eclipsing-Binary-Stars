#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

class Utilities {
    public:
        sf::Vector3f RotateAroundY(float angle, sf::Vector3f& vector);
        sf::Vector3f RotateAroundX(float angle, sf::Vector3f& vector);
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

        sf::Vector3f DotProduct(Matrix matrix, sf::Vector3f& vector);
    
};