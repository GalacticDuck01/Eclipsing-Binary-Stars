#pragma once

#include <SFML/Graphics.hpp>

// A Star Face is simply a triangle, consisting of three vertices
class StarFace {
    public:
        int index0;
        int index1;
        int index2;

        StarFace(int index0, int index1, int index2);
};