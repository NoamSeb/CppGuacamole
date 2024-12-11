#include "Block.h"


void Block::Tick(float DeltaTime)
{
	//(*shape).move(0.0f, 1.1f);

	sf::Vector2f movement;

	movement.x -= 0.125f;

	Move(movement);
}