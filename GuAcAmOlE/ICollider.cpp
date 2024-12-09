#include "ICollider.h"

#include <iostream>
#include "Main.h"
#include "MathUtils.h"

ICollider::ICollider()
{
	Main::CollidingObjects.push_back(this);
}

ICollider::~ICollider()
{
	std::list<ICollider*>::iterator it = std::find(Main::CollidingObjects.begin(), Main::CollidingObjects.end(), this);
	if (it != Main::CollidingObjects.end()) {
		Main::CollidingObjects.erase(it);
	}
	else {
		std::cout << "[ERROR] Didn't find object to delete in ~ICollider" << std::endl;
	}
}

