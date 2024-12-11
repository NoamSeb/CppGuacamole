#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "wtypes.h"
#include "Object.h"
#include "ICollider.h"

class Player : public Object, public ICollider
{
public:
	Player(float x, float y) : Object(Circle, true), posInit(x, y), ICollider (Circle){
		shape->setPosition(posInit);
		collisionShape->setPosition(posInit);
		
	};

	virtual void Init() override;

	void processEvents(sf::Keyboard::Key key, bool checkPressed);
	virtual void Tick(float DeltaTime) override;
	void drawTo(sf::RenderWindow& window);



private:
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;

	//Recup pos init
	sf::Vector2f posInit;

	// Inherited via ICollider
	void OnTriggerEnter(ICollider* collider) override;
};

