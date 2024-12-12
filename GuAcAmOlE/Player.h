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
	void TryDash(sf::Keyboard::Key key);
	virtual void Tick(float DeltaTime) override;
	void Dash(sf::Vector2f direction);
	void DecreaseDash(float DeltaTime);
	void drawTo(sf::RenderWindow& window);



private:
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;

	sf::Clock comboClock;
	const float comboDeltaTime = 0.5f;

	const float dashCooldown = 5.f;
	float timeSinceLastDash = 0.f;
	const float dashStrenght = 1.f;
	const float dashDecreasedStrenght = 5.f;
	sf::Vector2f dashMovement = sf::Vector2f(0, 0);

	sf::Keyboard::Key lastKeyInput = sf::Keyboard::Unknown;

	//Recup pos init
	sf::Vector2f posInit;

	// Inherited via ICollider
	void OnTriggerEnter(ICollider* collider) override;
};

