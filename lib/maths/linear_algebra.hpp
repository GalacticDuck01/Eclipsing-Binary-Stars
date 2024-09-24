#pragma once

#include <SFML/System/Vector3.hpp>
#include <math.h>

class LinearAlgebra {
    public:
        inline static sf::Vector3f Normalise(sf::Vector3f& vector) {
            float length = sqrt(vector.x*vector.x + vector.y*vector.y + vector.z*vector.z);
            return sf::Vector3f(vector.x/length, vector.y/length, vector.z/length);
        }
        static sf::Vector3f RotateAroundY(float angle, sf::Vector3f& vector);
        static sf::Vector3f RotateAroundX(float angle, sf::Vector3f& vector);
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

        static sf::Vector3f DotProduct(Matrix matrix, sf::Vector3f& vector);
    
};