#pragma once
#include"Object.h"
#include "ICollider.h"

class Block : public Object, public ICollider
{
public:

	Block() : Object(Rectangle, true), ICollider(Rectangle)
	{
	}

	virtual void Tick(float DeltaTime) override;
	virtual void OnTriggerEnter(ICollider* collider);
	float sdBox(sf::Vector2f p, sf::Vector2f b);
};