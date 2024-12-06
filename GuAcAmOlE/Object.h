#pragma once
#include <SFML/Graphics.hpp>

class Object
{
public:
	bool bTick = false;
	sf::Shape* shape;

	enum ShapeType
	{
		Circle,
		Rectangle,
		Triangle
	};

	virtual void Tick(float DeltaTime);
	void Destroy();
	Object(ShapeType shapeType, bool willTick);
	~Object();
};

