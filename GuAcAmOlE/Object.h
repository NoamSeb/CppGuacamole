#pragma once
#include <SFML/Graphics.hpp>

class Player;

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
	void Move(sf::Vector2f pos);
	Object(ShapeType shapeType, bool willTick);
	~Object();

	virtual void Init();
};

