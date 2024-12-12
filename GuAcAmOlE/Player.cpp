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
		TryDash(key);
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

void Player::TryDash(sf::Keyboard::Key key) {
	if (lastKeyInput == key) {
		if (comboClock.getElapsedTime().asSeconds() < comboDeltaTime) {
			if (timeSinceLastDash >= dashCooldown) {
				switch (key) {
					case sf::Keyboard::Up: {
						Dash(sf::Vector2f(0.f, -1.f));
						break;
					}
					case sf::Keyboard::Down: {
						Dash(sf::Vector2f(0.f, 1.f));
						break;
					}
					case sf::Keyboard::Right: {
						Dash(sf::Vector2f(1.f, 0.f));
						break;
					}
					case sf::Keyboard::Left: {
						Dash(sf::Vector2f(-1.f, 0.f));
						break;
					}
				}
				timeSinceLastDash = 0.f;
			}
		}
	}
	comboClock.restart();
	lastKeyInput = key;
}

void Player::Tick(float DeltaTime)
{
	Object::Tick(DeltaTime);

	timeSinceLastDash += DeltaTime;

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

	movement += dashMovement;
	DecreaseDash(DeltaTime);

	Move(movement);

}

void Player::Dash(sf::Vector2f direction) {
	std::cout << "Dash in direction: " << direction.x << ", " << direction.y << std::endl;
	dashMovement = sf::Vector2f(direction.x * dashStrenght, direction.y * dashStrenght);
}

void Player::DecreaseDash(float DeltaTime) {
	if (dashMovement.x > 0) {
		dashMovement.x = std::max(dashMovement.x - DeltaTime * dashDecreasedStrenght, 0.f);
	}
	else {
		dashMovement.x = std::min(dashMovement.x + DeltaTime * dashDecreasedStrenght, 0.f);
	}

	if (dashMovement.y > 0) {
		dashMovement.y = std::max(dashMovement.y - DeltaTime * dashDecreasedStrenght, 0.f);
	}
	else {
		dashMovement.y = std::min(dashMovement.y + DeltaTime * dashDecreasedStrenght, 0.f);
	}

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
