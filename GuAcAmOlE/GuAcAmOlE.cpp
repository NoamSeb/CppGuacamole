#include <iostream>

#include "Main.h"
#include "Object.h"
#include "Ennemy.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Avocado rush");
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
                    Ennemy* ennemies[3] = { nullptr };
                    for (int i = 0; i < 3; ++i) {
                        Ennemy* ennemy = new Ennemy();
                        ennemy->InitEnnemy();
                        ennemies[i] = ennemy;
                    }
					std::cout << "Ennemies created" << std::endl;
				}

                if (event.key.code == sf::Keyboard::Key::B)
                {
                    if (Main::ObjectToDraw.size() > 0)
                    {
                        Main::ObjectToDraw.front()->Destroy();
                    }
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