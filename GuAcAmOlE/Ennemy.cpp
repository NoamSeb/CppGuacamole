#include "Ennemy.h"

#include <iostream>
class Object;

void Ennemy::InitEnnemy()
{
	std::cout << "Init ennemies" << std::endl;
	Object* ennemy = new Object;
	ennemy->Create(Circle);
	dynamic_cast<sf::CircleShape*>(ennemy->shape)->setFillColor(sf::Color::Red);
	std::cout << "Ennemy created" << std::endl;
}