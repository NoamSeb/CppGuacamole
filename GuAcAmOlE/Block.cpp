#include "Block.h"

#include <iostream>
#include "MathUtils.h"
#include "Main.h"
#include "Player.h"


void Block::Tick(float DeltaTime)
{
	//(*shape).move(0.0f, 1.1f);

	sf::Vector2f movement;
	;
	movement.x -= Main::getCameraSpeed() * DeltaTime;

	Move(movement);
}

void Block::OnTriggerEnter(ICollider* collider)
{
	if (Player* player = dynamic_cast<Player*>(collider)) {
		float result = sdBox(collisionShape->getPosition(), collider->collisionShape->getPosition());
		std::cout << result << std::endl;
		if (result < 0)
		{
			player->Move(sf::Vector2f(result, 0));
		}
	}
}

void Block::Destroy()
{
	delete this;
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
