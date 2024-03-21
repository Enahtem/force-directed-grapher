using namespace std;
#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include <list>
#include <SFML/Graphics.hpp>
#include "graph.h"

void startup()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "CLICK TO START");
    window.setPosition(sf::Vector2i(0, 0));
    sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                // Check if the mouse click is inside the circle
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (shape.getGlobalBounds().contains(mousePosition))
                {
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

int main() 
{
    startup();
    testing();
    
    return 0;
}