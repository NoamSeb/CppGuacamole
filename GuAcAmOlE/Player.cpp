#include "Player.h"


class Player
{
public:
	Player(float x, float y)
	{
		rect.setSize(sf::Vector2f(x, y));

		up = false;
		down = false;
		left = false;
		right = false;
	};



	//~Player();

	//void MouvementDroite() {
	//	.move(5.0f, 0.0f);
	//}
	//void MouvementGauche() {
	//	.move(-5.0f, 0.0f);
	//}
	//
	//void MouvementBas() {
	//	.move(0.0f, -5.0f);
	//}




	void processEvents(sf::Keyboard::Key key, bool checkPressed) 
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

	void update()
	{
		sf::Vector2f movement;

		if (up)
		{
			movement.y -= 0.5f;
			

		}if (down)
		{
			movement.y += 0.5f;
		}
		if (left)
		{
			movement.x -= 0.5f;
		}if (right)
		{
			movement.x += 0.5f;
		}

		rect.move(movement);
	}

	void drawTo(sf::RenderWindow &window) 
	{
		window.draw(rect);
	}

private:

	sf::RectangleShape rect;

	bool up;
	bool down;
	bool left;
	bool right;
};


//Player::~Player()
//{
//}

//struct Vector2f
//{
//	float x;
//	float y;
//};


//float GetMagnitude(sf::Vector2f v)
//{
//	return sqrt(v.x * v.x + v.y * v.y);
//};
//
//sf::Vector2f Normalize(sf::Vector2f v)
//{
//	if (v.x == 0.f && v.y == 0.f)
//		return { 0.f, 0.f };
//	return v / GetMagnitude(v);
//};
