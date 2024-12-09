#pragma once

class ICollider
{
public:
	ICollider();
	~ICollider();

	virtual void OnTriggerEnter(Object* collider) = 0;
};

