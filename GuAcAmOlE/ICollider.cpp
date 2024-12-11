#include "ICollider.h"

#include <iostream>
#include "Main.h"


ICollider::ICollider(Object::ShapeType shapeType)
{
	switch (shapeType)
	{
	case Object::ShapeType::Circle:

		collisionShape = new sf::CircleShape();
		dynamic_cast<sf::CircleShape*>(collisionShape)->setRadius(50);

		break;
	case Object::ShapeType::Rectangle:

		collisionShape = new sf::RectangleShape();
		dynamic_cast<sf::RectangleShape*>(collisionShape)->setSize(sf::Vector2f(100, 100));

		break;
	default:
		std::cout << "Invalid shape type" << std::endl;
		break;
	}

	Main::CollidingObjects.push_back(this);
}

ICollider::ICollider(float x, float y)
{
	collisionShape = new sf::RectangleShape();
	dynamic_cast<sf::RectangleShape*>(collisionShape)->setSize(sf::Vector2f(x, y));

	Main::CollidingObjects.push_back(this);
}

ICollider::ICollider(float radius)
{
	collisionShape = new sf::CircleShape();
	dynamic_cast<sf::CircleShape*>(collisionShape)->setRadius(radius);

	Main::CollidingObjects.push_back(this);
}

ICollider::~ICollider()
{
	std::list<ICollider*>::iterator it = std::find(Main::CollidingObjects.begin(), Main::CollidingObjects.end(), this);
	if (it != Main::CollidingObjects.end()) {
		Main::CollidingObjects.erase(it);
	}
	else {
		std::cout << "[ERROR] Didn't find object to delete in ~ICollider" << std::endl;
	}
}

