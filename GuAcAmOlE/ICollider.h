#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

class ICollider
{
public:
	sf::Shape* collisionShape;

	ICollider(Object::ShapeType shapeType);
	~ICollider();

	virtual void OnTriggerEnter(ICollider* collider) = 0;
};

