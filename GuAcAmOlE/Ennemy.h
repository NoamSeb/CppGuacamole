#pragma once
#include "Object.h"
#include "ICollider.h"

class Ennemy : public Object, public ICollider
{
	public:
	Ennemy(Object::ShapeType shapeType, bool willTick) : Object(shapeType, true), ICollider(shapeType) {};
	Ennemy(float radius) : Object(true, radius), ICollider(radius) {};
	Ennemy(float width, float height) : Object(true, width, height), ICollider(width, height) {};

	virtual void Tick(float DeltaTime) override;

	// Inherited via ICollider
	void OnTriggerEnter(ICollider* collider) override;
};

