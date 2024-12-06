#include <iostream>
#include "SFML/Main.hpp"
#include "Main.h"
#include "Object.h"

int main()
{
  //sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "AvocadoRush", sf::Style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode(800, 600), "AvocadoRush");
    sf::Clock clock;
    
    while (window.isOpen()) {
        float deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            // Process any input event here
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
				if (event.key.code == sf::Keyboard::Key::Space)
				{
					Object* object = new Object(Object::ShapeType::Circle, true);
				}

                if (event.key.code == sf::Keyboard::Key::B)
                {
                    if (Main::Objects.size() > 0)
                    Main::Objects.front()->Destroy();
                }
            }
        }

        // LOGIC

        for (auto objectToTick : Main::Objects) {
            if (objectToTick->bTick) {
                objectToTick->Tick(deltaTime);
            }
        }

        window.clear();
        
        // RENDER

        for (auto objectToDraw : Main::Objects)
        {
			window.draw(*(objectToDraw->shape));
        }

        window.display();
    }
}