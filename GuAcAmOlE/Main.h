#pragma once
#include <list>

class Object;
class ICollider;

namespace Main
{
	extern std::list<Object*> Objects;
	extern std::list<ICollider*> CollidingObjects;
	void EnnemySpawner();
};

