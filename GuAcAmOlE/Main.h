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
	extern std::vector<float> posObt;
	//extern std::vector<Object*> listObt;

	extern float widthEcran;


	//extern void spawnObt(float deltaTime, float timeSpawn, std::vector<float> posObt, std::vector<Object*> listObt);
	extern void spawnObt(float deltaTime);
	extern void DeleteObt();

	extern void DeleteAllObt();
};
