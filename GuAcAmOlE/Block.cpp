#include "Block.h"

#include <iostream>
#include "MathUtils.h"
#include "Player.h"


void Block::Tick(float speed)
{
	//(*shape).move(0.0f, 1.1f);

	sf::Vector2f movement;

	movement.x -= 0.15f;

	Move(movement);
}

void Block::OnTriggerEnter(ICollider* collider)
{
	float result = sdBox(collisionShape->getPosition() - collider->collisionShape->getPosition(), sf::Vector2f(50, 50));
	if (result < 0)
	{
		if (dynamic_cast<Player*>(collider)) {
			// If enemy hit player
			std::cout << "Player hit block" << std::endl;
		}
		std::cout << "Collision happened" << std::endl;
	}
}

float Block::sdBox(sf::Vector2f p, sf::Vector2f b)
{
	sf::Vector2f d =
	{
		abs(p.x) - b.x, abs(p.y) - b.y
	};
	sf::Vector2f maxD =
	{
		std::max(d.x, 0.0f), std::max(d.y, 0.0f)
	};
	std::cout << IIM::GetMagnitude(maxD) + std::min(std::max(d.x, d.y), 0.0f) << std::endl;
	return IIM::GetMagnitude(maxD) + std::min(std::max(d.x, d.y), 0.0f);
}
