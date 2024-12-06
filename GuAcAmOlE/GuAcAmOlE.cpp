#include <iostream>
#include "SFML/Main.hpp"
#include "Main.h"
#include "Object.h"
#include "Player.h"
#include "Ennemy.h"
#include "HUD.h"

int main()
{
  //sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "AvocadoRush", sf::Style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode(800, 600), "AvocadoRush");
    sf::Clock clock;

    //Get l'insatnce de HUD
    HUD* _HUD = HUD::getInstance();
    _HUD->LoadFont(); // pr tous les texts

    Player player(100.0f, 100.0f);
	Main::EnnemySpawner();


    //Timer
    float timeElapsed=0;

    //Restart
    //bool go = true;

    
    while (window.isOpen()) 
    {
        //if (go != false) {
        float deltaTime = clock.getElapsedTime().asSeconds();
        timeElapsed += clock.getElapsedTime().asSeconds();
        clock.restart();
        //}


        sf::Event event;
        while (window.pollEvent(event)) {

            // Process any input event here
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            //if (go == false) {
                if (event.type == sf::Event::KeyPressed)
                {

                    if (event.key.code == sf::Keyboard::Key::K)
                    {
                        //go = true;
                        std::cout << "Recommence" << std::endl;
                    }
                }
            //}
            //else {

                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Key::Space)
                    {

                        //go = false;
                        Object* object = new Object(Object::ShapeType::Circle, true);
                    }

                    if (event.key.code == sf::Keyboard::Key::B)
                    {
                        if (Main::Objects.size() > 0)
                            Main::Objects.front()->Destroy();
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