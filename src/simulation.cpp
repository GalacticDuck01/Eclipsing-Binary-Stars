#include <simulation.hpp>

Simulation::Simulation() {
    Star star = Star(3);
    stars.push_back(star);
}

Simulation::~Simulation() {

}

/*!
    Draws the simulation to the screen.
    @param window: Reference to the window.
*/
void Simulation::Draw(sf::RenderWindow& window) {
    for (auto& star: stars) {
        star.Draw(window);
    }
    
}

void Simulation::Update() {

}

void Simulation::HandleInput() {

}