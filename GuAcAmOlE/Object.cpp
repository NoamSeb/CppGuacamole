#include "Object.h"
#include <iostream>
#include "Main.h"
#include "ICollider.h"

Object::Object(ShapeType shapeType, bool willTick) {
	bTick = willTick;

	switch (shapeType)
	{
	case Circle:

		shape = new sf::CircleShape();
		dynamic_cast<sf::CircleShape*>(shape)->setRadius(50);

		break;
	case Rectangle:

		shape = new sf::RectangleShape();
		dynamic_cast<sf::RectangleShape*>(shape)->setSize(sf::Vector2f(100, 100));
		shape->setOrigin(50, 50);

		break;
	default:
		std::cout << "Invalid shape type" << std::endl;
		Destroy();
		break;
	}

	Main::Objects.push_back(this);
}

Object::~Object()
{
	std::list<Object*>::iterator it = std::find(Main::Objects.begin(), Main::Objects.end(), this);
	if (it != Main::Objects.end()) {
		Main::Objects.erase(it);
	}
	delete shape;
}

void Object::Tick(float DeltaTime)
{
	if (!bTick) {
		return;
	}
}

void Object::Destroy()
{
	delete this;
}

void Object::Move(sf::Vector2f pos)
{
	shape->move(pos);
	if (ICollider* coll = dynamic_cast<ICollider*>(this)) {
		coll->collisionShape->move(pos);
	}
}

void Object::SetPosition(sf::Vector2f pos)
{
	shape->setPosition(pos);
	if (ICollider* coll = dynamic_cast<ICollider*>(this)) {
		coll->collisionShape->setPosition(pos);
	}
}

void Object::SetPosition(float x, float y)
{
	SetPosition(sf::Vector2f(x, y));
}

void Object::Init() {
}
