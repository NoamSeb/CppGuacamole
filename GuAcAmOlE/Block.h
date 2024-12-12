#pragma once
#include"Object.h"
#include "ICollider.h"

class Block : public Object, public ICollider
{
public:

	Block() : Object(Rectangle, true), ICollider(Rectangle){}
	Block(float width, float height) : Object(true, width, height), ICollider(width, height) {}
	Block(float radius) : Object(true, radius), ICollider(radius) {}

	virtual void Tick(float DeltaTime) override;
	virtual void OnTriggerEnter(ICollider* collider);
	virtual void Destroy() override;
	float sdBox(sf::Vector2f p, sf::Vector2f b);
};