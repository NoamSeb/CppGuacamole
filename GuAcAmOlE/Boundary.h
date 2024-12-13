#pragma once
#include "Object.h"
#include "ICollider.h"

class Boundary : public Object, public ICollider
{

public:
	Boundary(float width, float height) : Object(true, width, height), ICollider(width, height) {};

	float sdBox(sf::Vector2f p, sf::Vector2f b);
	void Destroy() override;
	void OnTriggerEnter(ICollider* collider) override;
};