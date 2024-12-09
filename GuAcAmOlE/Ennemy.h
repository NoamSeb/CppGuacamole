#pragma once
#include "Object.h"
#include "ICollider.h"

class Ennemy : public Object, public ICollider
{
	virtual void Tick(float DeltaTime) override;

	// Inherited via ICollider
	void OnTriggerEnter(ICollider* collider) override;
};

