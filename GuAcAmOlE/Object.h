#pragma once
#include <SFML/Graphics.hpp>

class Object
{
public:
	sf::Shape* shape;

	enum ShapeType
	{
		Circle,
		Rectangle,
		Triangle
	};

	void Create(ShapeType shapeType);
	void Destroy(sf::RenderWindow window);
};

