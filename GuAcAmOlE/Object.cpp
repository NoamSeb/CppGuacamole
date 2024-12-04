#include "Object.h"
#include <iostream>
#include "Main.h"

void Object::Create(ShapeType shapeType)
{
	switch (shapeType)
	{
	case Circle:
		{
			shape = new sf::CircleShape();
			static_cast<sf::CircleShape*>(shape)->setRadius(50);
		}
		break;
	case Rectangle:
		{
			shape = new sf::RectangleShape();
			static_cast<sf::RectangleShape*>(shape)->setSize(sf::Vector2f(100, 100));
		}
		break;
	case Triangle:
		{
			shape = new sf::ConvexShape();
			static_cast<sf::ConvexShape*>(shape)->setPointCount(3);
		}
		break;
	//default:
	//	std::cout << "Invalid shape type" << std::endl;
	//	break;
	}

	Main::ObjectToDraw.push_back(*this);
}
void Object::Destroy(sf::RenderWindow window)
{
	for (int i = 0; i < Main::ObjectToDraw.size(); i++)
	{
		if (Main::ObjectToDraw[i].shape == shape)
		{
			Main::ObjectToDraw.erase(Main::ObjectToDraw.begin() + i);
			break;
		}
	}
	delete shape;
}