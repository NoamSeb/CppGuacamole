#include "Main.h"

#include <iostream>
#include "Object.h"

std::list<Object*> Main::Objects;
std::list<ICollider*> Main::CollidingObjects;

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

