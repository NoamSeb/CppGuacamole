// GuAcAmOlE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "wtypes.h"

using namespace std;
using namespace sf;

int main()
{
    sf::CircleShape circle; // Déclaration de "circle" (sans affectation)
    circle.setFillColor(sf::Color::Red);
    circle.setRadius(100.0f); // Appel de méthode qui travaille sur "circle"

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "AvocadoRush", sf::Style::Fullscreen);

    // Initialise everything below
    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Process any input event here
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();

        //Dessine à chaque frame
        window.draw(circle);

        window.display();
    }
}