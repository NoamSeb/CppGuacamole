#include "Object.h"
#include <iostream>
#include "Main.h"


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

		break;
	case Triangle:

		shape = new sf::ConvexShape();
		dynamic_cast<sf::ConvexShape*>(shape)->setPointCount(3);

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
	std::cout << DeltaTime << std::endl;
}

void Object::Destroy()
{
	delete this;
}
