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
		//float result = sdBox(collider->collisionShape->getPosition() - collisionShape->getPosition(), sf::Vector2f(50, 50));
		//if (result > 0)
		//{
		//	player->Move(sf::Vector2f(-result, 0));
		//}
		std::cout << "Player touched boundary" << std::endl;
	}
}

void Boundary::Destroy()
{
	delete this;
}