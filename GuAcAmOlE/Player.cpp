#include "Player.h"

#include "Main.h"

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
		if (key == sf::Keyboard::Up)
		{
			up = false;
		}
		if (key == sf::Keyboard::Down)
		{
			down = false;
		}
		if (key == sf::Keyboard::Left)
		{
			left = false;
		}
		if (key == sf::Keyboard::Right)
		{
			right = false;
		}
	}
}

void Player::Tick(float DeltaTime)
{
	Object::Tick(DeltaTime);

	sf::Vector2f speed(400, 400);
	sf::Vector2f movement;

	if (up)
	{
		movement.y -= speed.y * DeltaTime;

	}if (down)
	{
		movement.y += speed.y * DeltaTime;
	}
	if (left)
	{
		movement.x -= speed.x * DeltaTime;
	}
	if (right)
	{
		movement.x += speed.x * DeltaTime;
	}
	//auto move back
	else {
		movement.x -= Main::getCameraSpeed() * DeltaTime;
	}

	Move(movement);

}

void Player::drawTo(sf::RenderWindow& window)
{
	window.draw((*shape));
}

void Player::OnTriggerEnter(ICollider* collider)
{
	// Player collided with something
}

void Player::Init() {
	shape->setPosition(posInit);
	collisionShape->setPosition(posInit);
}
