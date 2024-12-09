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

        std::vector<Object*> objectsToCheck(Main::CollidingObjects.begin(), Main::CollidingObjects.end());

        for (int i = 0; i < objectsToCheck.size(); i++) {
            for (int j = 0; j < objectsToCheck.size(); j++)
            {
                Object* a = objectsToCheck[i];
                Object* b = objectsToCheck[j];
                if (i != j) {
                    //if (CollisionCheck(Main::Objects[i], Main::Objects[j]){
                    //
                    //}
                    if (a->shape->getGlobalBounds().intersects(b->shape->getGlobalBounds())) { // Both rectangle intersects
                        dynamic_cast<ICollider*>(a)->OnTriggerEnter(b);
                        dynamic_cast<ICollider*>(b)->OnTriggerEnter(a);
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