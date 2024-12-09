#pragma once
#include <list>
#include "ICollider.h"

class Object;

namespace Main
{
	extern std::list<Object*> Objects;
	extern std::list<ICollider*> CollidingObjects;
	void EnnemySpawner();
};

