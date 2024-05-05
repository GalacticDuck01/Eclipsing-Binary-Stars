#include <star.hpp>

Star::Star(int recursionLevel) : starMesh(recursionLevel){
    position = sf::Vector3f(350.f, 350.f, 0.f);
    radius = 300;
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

void Star::Update() {

}

void Star::RotateAroundXAxis(float theta) {
    starMesh.RotateAroundXAxis(theta);
}

void Star::RotateAroundYAxis(float phi) {
    starMesh.RotateAroundYAxis(phi);
}