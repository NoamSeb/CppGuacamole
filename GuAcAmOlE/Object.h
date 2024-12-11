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

	Object(ShapeType shapeType, bool willTick);
	Object(bool willTick, float width, float height);
	Object(bool willTick, float radius);
	~Object();

	virtual void Tick(float DeltaTime);
	virtual void Destroy();
	void Move(sf::Vector2f pos);
	void SetPosition(sf::Vector2f pos);
	void SetPosition(float x, float y);

	virtual void Init();
};

