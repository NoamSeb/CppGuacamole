#pragma once
#include "Object.h"
#include "ICollider.h"

class Ennemy : public Object, public ICollider
{
	public:
	Ennemy(Object::ShapeType shapeType, bool willTick) : Object(shapeType, willTick), ICollider(shapeType) {};

	virtual void Tick(float DeltaTime) override;

	// Inherited via ICollider
	void OnTriggerEnter(ICollider* collider) override;
};

