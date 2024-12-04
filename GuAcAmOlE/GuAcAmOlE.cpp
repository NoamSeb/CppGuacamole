#include "Main.h"
#include "Object.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Avocado run");
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
					Object object;
                    object.Create(Object::ShapeType::Circle);
				}

            }
        }
        window.clear();
        for (auto object_to_draw : Main::ObjectToDraw)
        {
			window.draw(*object_to_draw.shape);
        }
        window.display();
    }
}
