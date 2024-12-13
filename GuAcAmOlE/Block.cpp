#include "Block.h"

#include <iostream>
#include "MathUtils.h"
#include "Main.h"
#include "Player.h"
#include "math.h"

void Block::Tick(float DeltaTime)
{
	sf::Vector2f movement;
	movement.x -= Main::getCameraSpeed() * DeltaTime * exp(sqrt(Main::timeElapsed / 60));
	// Difficulté au début: 1x
	// à 10s: 1.09x
	// à 30s: 1.18x
	// à 60s: 1.65x
	// à 120s : 2.72x
	// à 300s : 12.18x
	
	Move(movement);
}

void Block::OnTriggerEnter(ICollider* collider)
{
	if (Player* player = dynamic_cast<Player*>(collider)) {
		sf::Vector2f vec = dynamic_cast<sf::RectangleShape*>(collisionShape)->getSize() / 2.f;
		float radius = dynamic_cast<sf::CircleShape*>(collider->collisionShape)->getRadius();
		float result = sdBox(collisionShape->getPosition() - collider->collisionShape->getPosition(), sf::Vector2f(vec.x + radius, vec.y + radius));
		if (result < 0)
		{
			std::cout << result << std::endl;
			switch (collideDirection) {
			case Direction::UP:
				player->Move(sf::Vector2f(0, result));
				break;
			case Direction::DOWN:
				player->Move(sf::Vector2f(0, -result));
				break;
			case Direction::LEFT:
				player->Move(sf::Vector2f(result, 0));
				break;
			case Direction::RIGHT:
				player->Move(sf::Vector2f(-result, 0));
				break;
			}
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
	// std::cout << IIM::GetMagnitude(maxD) + std::min(std::max(d.x, d.y), 0.0f) << std::endl;
	return IIM::GetMagnitude(maxD) + std::min(std::max(d.x, d.y), 0.0f);
}
