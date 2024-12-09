#include "Main.h"

#include <iostream>

#include "Object.h"


std::list<Object*> Main::Objects;

void Main::EnnemySpawner()
{
    Object* ennemies[3] = { nullptr };
    for (int i = 0; i < 3; ++i) {
        Object* ennemy = new Object(Object::ShapeType::Circle, true);
		dynamic_cast<sf::CircleShape*>(ennemy->shape)->setFillColor(sf::Color::Red);
        ennemies[i] = ennemy;
    }
    std::cout << "Ennemies created" << std::endl;
}



void Main::DeleteAllEnemies() {
}


void Main::InitAllObjects() {
    for (auto it = Main::Objects.begin(); it != Main::Objects.end(); ) {

        //Supp tous les enemies
        if (typeid(**it) != typeid(Player)) { // plus tard == id Ennemy
            std::cout << " Enemy on supp." << std::endl;
            //Check si vrmt supp ou jst n apparait plus
            it = Main::Objects.erase(it);  
        }

        // init etat de tout autre objet
        else {
            (*it)->Init();
            ++it;
        }
    }
}