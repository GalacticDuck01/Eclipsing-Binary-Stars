#include <star.hpp>

Star::Star() {
    sf::CircleShape triangle = sf::CircleShape(80, 3);
    surfaces.push_back(triangle);
}

Star::~Star() {

}

void Star::Draw(sf::RenderWindow& window) {
    for (auto& surface : surfaces) {
        std::cout << "Printed a surface!" << std::endl;
        window.draw(surface);
    }
    
}
