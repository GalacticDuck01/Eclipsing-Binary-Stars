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
    for (auto& star: stars) {
        star.Update();
    }
}

void Simulation::HandleInput(sf::Event& event) {
    if (event.type == sf::Event::EventType::KeyPressed) {
        float angle = 1*M_PI/180.f;
        if (event.key.code == sf::Keyboard::Up) {
            for (auto& star: stars) {
                star.RotateAroundXAxis(angle);
            }
        }
        else if (event.key.code == sf::Keyboard::Down) {
            for (auto& star: stars) {
                star.RotateAroundXAxis(-angle);
            }
        }

        if (event.key.code == sf::Keyboard::Right) {
            for (auto& star: stars) {
                star.RotateAroundYAxis(angle);
            }
        }
        else if (event.key.code == sf::Keyboard::Left) {
            for (auto& star: stars) {
                star.RotateAroundYAxis(-angle);
            }
        }
    }
}
