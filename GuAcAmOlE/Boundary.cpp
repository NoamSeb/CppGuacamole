#include "Boundary.h"
#include "Player.h"
#include "MathUtils.h"

float Boundary::sdBox(sf::Vector2f p, sf::Vector2f b)
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

void Boundary::OnTriggerEnter(ICollider* collider)
{
	if (Player* player = dynamic_cast<Player*>(collider)) {
		float result = sdBox(collisionShape->getPosition(), collider->collisionShape->getPosition());
		if (result < 0)
		{
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

void Boundary::Destroy()
{
	delete this;
}