#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "wtypes.h"
#include "Object.h"

class Player : public Object
{
public:
	Player(float x, float y) : Object(Circle, true) {
	};
	void processEvents(sf::Keyboard::Key key, bool checkPressed);
	virtual void Tick(float DeltaTime) override;
	void drawTo(sf::RenderWindow& window);

private:
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
};

