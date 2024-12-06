// GuAcAmOlE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "wtypes.h"
#include "Player.cpp"

using namespace std;
using namespace sf;

int main()
{
    sf::RectangleShape rectangle({ 100.f, 100.f }); // Déclaration de "circle" (sans affectation)
    rectangle.setFillColor(sf::Color::Green);
    

    //sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "AvocadoRush", sf::Style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "ChronoSpacer");



    Player player(100.0f, 100.0f);
    



    // Initialise everything below
    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Process any input event here


            //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            //    std::cout << "ok " <<std::endl;
            //}


            //if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
            //{
            //    std::cout << "aaaaa" << std::endl;
            //}

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                rectangle.move(0.0f, 5.0f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                rectangle.move(0.0f, -5.0f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                rectangle.move(5.0f, 0.0f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                rectangle.move(-5.0f, 0.0f);
            }



            //sf::Vector2f movement(0.f, 0.f);
            //if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y += 1.f; //Here we should add 1
            //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) movement.y -= 1.f; //Here we should substract 1
            //if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x -= 1.f;
            //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) movement.x += 1.f;
            //
            //rectangle.move(movement);



            if (event.type == sf::Event::KeyPressed)
            {
                player.processEvents(event.key.code, true);
            }
            if (event.type == sf::Event::KeyReleased)
            {
                player.processEvents(event.key.code, false);
            }




            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }




        window.clear();

        player.update();

        //Dessine à chaque frame
        window.draw(rectangle);


        player.drawTo(window);


        window.display();
    }
}