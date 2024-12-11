#pragma once
#include <vector>
#include <list>
#include "Object.h"
#include "Block.h"

class Ennemy;
class Object;
class ICollider;

namespace Main
{
	extern std::list<Object*> Objects;
	extern std::list<ICollider*> CollidingObjects;

	enum GameState
	{
		Playing,
		GameOver
	};

	extern GameState gameState;

	Ennemy* SpawnDeathZone();
	void InitAllObjects();
	//extern float timeSpawn;
	//
	extern std::vector<float> posObt;
	//extern std::vector<Object*> listObt;

	extern float widthEcran;
	extern float heightEcran;


	//extern void spawnObt(float deltaTime, float timeSpawn, std::vector<float> posObt, std::vector<Object*> listObt);
	extern void spawnObt(float deltaTime);
	extern void DeleteTwoFirtsBlocks();

	extern void DeleteAllBlocks();
	extern void GameOverLogic();
	//extern void InitGame();
};
