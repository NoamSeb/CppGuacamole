#pragma once
#include <vector>
#include <list>
#include "Object.h"
#include "Block.h"

class Object;

namespace Main
{
	extern std::list<Object*> Objects;
	void EnnemySpawner();
	void DeleteAllEnemies();
	void InitAllObjects();
	//extern float timeSpawn;
	//
	//extern std::vector<float> posObt = { 0.0f, 300.0f, 600.0f };
	//extern std::vector<Object*> listObt;

	//extern void spawnObt(float deltaTime, float timeSpawn, std::vector<float> posObt, std::vector<Object*> listObt);
	extern void spawnObt(float deltaTime);
};
