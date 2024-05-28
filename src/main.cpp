#include <SFML/Graphics.hpp>

#include <simulation.hpp>
#include <fps_tracker.hpp>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(700, 700), "Eclipsing Binary Stars", sf::Style::Default, settings);

    Simulation simulation = Simulation();
    FpsTracker fps = FpsTracker();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            simulation.HandleInput(event);
        }

        simulation.Update();
        fps.Update();

        window.clear();

        // window.draw(shape);
        simulation.Draw(window);

        window.display();
    }

    return 0;
}