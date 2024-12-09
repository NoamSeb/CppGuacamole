#pragma once

#include <SFML/Graphics.hpp>

class ICollider
{
public:
	sf::Shape* collisionShape = new sf::RectangleShape();

	ICollider();
	~ICollider();

	virtual void OnTriggerEnter(ICollider* collider) = 0;
};

