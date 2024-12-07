#pragma once
#include <list>

class Object;

namespace Main
{
	extern std::list<Object*> Objects;
	void EnnemySpawner();
	void DeleteAllObjects();
};

