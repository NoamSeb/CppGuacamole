#include <iostream>
#include "wtypes.h"

using namespace std;
using namespace sf;

#include "Main.h"
#include "Object.h"

int main()
{
  //sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "AvocadoRush", sf::Style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode(800, 600), "AvocadoRush");
    // Initialise everything below
    // Game loop
    while (window.isOpen()) {
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
					Object* object = new Object();
                    object->Create(Object::ShapeType::Circle);
				}

                if (event.key.code == sf::Keyboard::Key::B)
                {
                    if (Main::ObjectToDraw.size() > 0)
                    Main::ObjectToDraw.front()->Destroy();
                }
            }
        }
        window.clear();
        for (auto object_to_draw : Main::ObjectToDraw)
        {
			window.draw(*(object_to_draw->shape));
        }
        window.display();
    }
}