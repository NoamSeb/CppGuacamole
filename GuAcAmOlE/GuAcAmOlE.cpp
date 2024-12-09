#include <iostream>
#include "SFML/Main.hpp"
#include "Main.h"
#include "Object.h"
#include "Player.h"
#include "Ennemy.h"
#include "HUD.h"
#include "Block.h"

int main()
{
  //sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "AvocadoRush", sf::Style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode(800, 600), "AvocadoRush");
    sf::Clock clock;

    //Get l'instance de HUD
    HUD* _HUD = HUD::getInstance();
    _HUD->LoadFont(); // pr tous les texts

    Player player(300.0f, 250.0f);
    //std::cout << player.posInit.x << std::endl;
	Main::EnnemySpawner();

    //Timer
    float timeElapsed=0;

    //Restart
    //bool gameOver = true;

    
    while (window.isOpen()) 
    {
        float deltaTime = clock.getElapsedTime().asSeconds();
        timeElapsed += deltaTime;
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
                    if (event.key.code == sf::Keyboard::Key::R) //Restart
                    {
                        std::cout << "Init Game" << std::endl;
                        timeElapsed = 0;
                        _HUD->InitGame();
                        //Main::EnnemySpawner();
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
            //}

        }

        Main::spawnObt(deltaTime);

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

        sf::Text myTimer = _HUD->CreateTimerText(timeElapsed);
        window.draw(myTimer);


        window.display();
    }
}