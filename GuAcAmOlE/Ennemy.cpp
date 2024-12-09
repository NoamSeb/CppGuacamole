#include "Ennemy.h"

#include <iostream>
#include "Player.h"
class Object;

void Ennemy::Tick(float DeltaTime)
{
	std::cout << "Ennemy ticked" << std::endl;
}

void Ennemy::OnTriggerEnter(ICollider* collider)
{
	if (dynamic_cast<Player*>(collider)) {
		// If enemy hit player
	}
	std::cout << "Collision happened" << std::endl;
}
