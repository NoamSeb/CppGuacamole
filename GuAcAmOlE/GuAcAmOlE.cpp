#include <iostream>
#include "SFML/Main.hpp"
#include "Main.h"
#include "Object.h"
#include "Player.h"
#include "Ennemy.h"
#include "HUD.h"
#include "Block.h"
#include "ICollider.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "AvocadoRush", sf::Style::Fullscreen);
	//sf::RenderWindow window(sf::VideoMode(800, 600), "AvocadoRush");
    Main::posObt = { 0.0f, (float)window.getSize().y / 3 , (float)window.getSize().y - (float)window.getSize().y / 3 };
	Main::widthEcran = (float)window.getSize().x;
	Main::heightEcran = (float)window.getSize().y;

	sf::Clock clock;
	
    Main::InitGame();

	while (window.isOpen())
	{
		float deltaTime = clock.getElapsedTime().asSeconds();
		Main::timeElapsed += deltaTime;
		clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {

            // Process any input event here
            if (event.type == sf::Event::Closed) {
                window.close();
            }
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Key::R) //Restart
                    {
                        if (Main::gameState == Main::GameOver) {
                            Main::InitGame();
                        }
                    }
                }
                if (event.type == sf::Event::KeyPressed)
                {
                    Main::player->processEvents(event.key.code, true);
                }
                if (event.type == sf::Event::KeyReleased)
                {
                    Main::player->processEvents(event.key.code, false);
                }
        }

        // COLLISION

        for (ICollider* colliderA : Main::CollidingObjects) {
            if (Main::gameState == Main::GameOver) {
                break;
            }
            for (ICollider* colliderB : Main::CollidingObjects) {
                if (Main::gameState == Main::GameOver) {
                    break;
                }
               if (colliderA != colliderB) {
                   if (colliderA->collisionShape->getGlobalBounds().intersects(colliderB->collisionShape->getGlobalBounds())) { // Both rectangle intersects
                       colliderA->OnTriggerEnter(colliderB);
                       // dynamic_cast<ICollider*>(b)->OnTriggerEnter(a); can be used if we skipped next iteration on same object
                   }
               }
            }
        }

        if (Main::gameState == Main::GameOver) {
            Main::CollidingObjects.clear();
        }

        // LOGIC

        Main::spawnBlocks(deltaTime);

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


        if (Main::gameState == Main::Playing)
        {
            sf::Text myTimer = Main::_HUD->CreateTimerText(Main::timeElapsed);
            window.draw(myTimer);
        }
        else {
            sf::Text GameOver = Main::_HUD->CreateText("Game Over", 200, sf::Vector2f(Main::widthEcran / 2.0f, Main::heightEcran / 2.0f), sf::Color::Red);
            sf::Text Restart = Main::_HUD->CreateText("Press R to Restart", 50, sf::Vector2f(Main::widthEcran/2.0f, Main::heightEcran/2.0f - 100), sf::Color::Red);
            window.draw(GameOver);
            window.draw(Restart);
        }

		window.display();
	}
}