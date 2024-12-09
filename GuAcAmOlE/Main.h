#pragma once
#include <list>
#include "Object.h"
#include "Player.h"
#include "Ennemy.h"

class Object;

namespace Main
{
	extern std::list<Object*> Objects;
	void EnnemySpawner();
	void DeleteAllEnemies();
	void InitAllObjects();
};

