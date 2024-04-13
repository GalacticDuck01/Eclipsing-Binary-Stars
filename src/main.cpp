#include <SFML/Graphics.hpp>

#include <simulation.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Eclipsing Binary Stars", sf::Style::Default, settings);

    Simulation simulation = Simulation();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // window.draw(shape);
        simulation.Draw(window);

        window.display();
    }

    return 0;
}