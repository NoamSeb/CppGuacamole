#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

class ICollider
{
public:
	sf::Shape* collisionShape;

	ICollider(Object::ShapeType shapeType);
	ICollider(float radius);
	ICollider(float width, float height);
	~ICollider();

	virtual void OnTriggerEnter(ICollider* collider) = 0;
};

