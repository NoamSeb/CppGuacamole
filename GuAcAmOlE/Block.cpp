#include "Block.h"


void Block::Tick(float DeltaTime)
{
	//(*shape).move(0.0f, 1.1f);

	sf::Vector2f movement;

	movement.y += 1.0f;

	(*shape).move(movement);
}