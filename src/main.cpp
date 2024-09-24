#include <SFML/Graphics.hpp>

#include <simulation.hpp>

int main()
{
    const u_int screenWidth = 1080;
    const u_int screenHeight = 720;
    auto window = sf::RenderWindow{ { screenWidth, screenHeight }, "Star Simulator" };

    Simulation simulation = Simulation();

    sf::Clock clock;
    float lastFrameTime = 0.f;

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }

        simulation.HandleInput();

        float currentFrameTime = clock.getElapsedTime().asSeconds();
        float deltaTime = currentFrameTime - lastFrameTime;
        lastFrameTime = currentFrameTime;

        simulation.Update(deltaTime);

        simulation.Draw(sf::Vector2f{(float)screenWidth/2.f, (float)screenHeight/2.f});

        window.clear();
        Renderer::GetRenderer().Draw(window);
        window.display();
    }
}