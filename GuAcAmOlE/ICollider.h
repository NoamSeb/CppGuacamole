#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};


class ICollider
{
public:
	sf::Shape* collisionShape;
	Direction collideDirection;

	ICollider(Object::ShapeType shapeType);
	ICollider(float radius);
	ICollider(float width, float height);
	~ICollider();

	virtual void OnTriggerEnter(ICollider* collider) = 0;
};


