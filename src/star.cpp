#include <star.hpp>

Star::Star(int recursionLevel) : starMesh(recursionLevel){
    position = sf::Vector3f(350.f, 350.f, 0.f);
    radius = 300;
    theta = 0.f;
    phi = 0.f;
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
    starMesh.Update(theta, phi);
}

void Star::RotateAroundXAxis(float deltaTheta) {
    theta += deltaTheta;
}

void Star::RotateAroundYAxis(float deltaPhi) {
    phi += deltaPhi;
}