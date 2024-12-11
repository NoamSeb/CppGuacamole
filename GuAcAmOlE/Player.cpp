#include "Player.h"

//Player::Player(float x, float y) :Object(Circle, true)
//{
//	//(*shape).setSize(sf::Vector2f(x, y));
//
//	up = false;
//	down = false;
//	left = false;
//	right = false;
//}




void Player::processEvents(sf::Keyboard::Key key, bool checkPressed)
{
	if (checkPressed)
	{
		if (key == sf::Keyboard::Up)
		{
			up = true;
		}
		if (key == sf::Keyboard::Down)
		{
			down = true;
		}
		if (key == sf::Keyboard::Left)
		{
			left = true;
		}
		if (key == sf::Keyboard::Right)
		{
			right = true;
		}
	}

	if (!checkPressed)
	{
		up = false;
		down = false;
		left = false;
		right = false;
	}
}

void Player::Tick(float DeltaTime)
{
	Object::Tick(DeltaTime);

	sf::Vector2f movement;

	if (up)
	{
		movement.y -= 0.1f;

	}if (down)
	{
		movement.y += 0.1f;
	}
	if (left)
	{
		movement.x -= 0.1f;
	}if (right)
	{
		movement.x += 0.1f;
	}

	Move(movement);

}

void Player::drawTo(sf::RenderWindow& window)
{
	window.draw((*shape));
}

void Player::Init() {
	shape->setPosition(posInit);
}
