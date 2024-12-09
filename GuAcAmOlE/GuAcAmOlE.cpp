#include <iostream>
#include "SFML/Main.hpp"
#include "Main.h"
#include "Object.h"
#include "Player.h"
#include "Ennemy.h"
#include "ICollider.h"

int main()
{
  //sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "AvocadoRush", sf::Style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode(800, 600), "AvocadoRush");
    sf::Clock clock;
    Player player(100.0f, 100.0f);
	Main::EnnemySpawner();
    
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
                    if (Main::Objects.size() > 0) {
                        Main::Objects.front()->Destroy();
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed)
            {
                player.processEvents(event.key.code, true);
            }
            if (event.type == sf::Event::KeyReleased)
            {
                player.processEvents(event.key.code, false);
            }

        }

        // COLLISION

        for (ICollider* colliderA : Main::CollidingObjects) {
            for (ICollider* colliderB : Main::CollidingObjects) {
                if (colliderA != colliderB) {
                    if (colliderA->collisionShape->getGlobalBounds().intersects(colliderB->collisionShape->getGlobalBounds())) { // Both rectangle intersects
                        dynamic_cast<ICollider*>(colliderA)->OnTriggerEnter(colliderB);
                        // dynamic_cast<ICollider*>(b)->OnTriggerEnter(a); can be used if we skipped next iteration on same object
                    }
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
;
        
        // RENDER

        for (auto objectToDraw : Main::Objects)
        {
			window.draw(*(objectToDraw->shape));
        }

        window.display();
    }
}