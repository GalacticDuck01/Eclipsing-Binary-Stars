#include <star.hpp>

Star::Star(int recursionLevel) : starMesh(recursionLevel){
    position = sf::Vector3f(500.f, 500.f, 0.f);
    radius = 400;
}

Star::~Star() {
}

/*!
    Draws the star to the screen.
    @param window: Reference to the window.
*/
void Star::Draw(sf::RenderWindow& window) {
    starMesh.Draw(window, position, radius);
}