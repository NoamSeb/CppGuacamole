#pragma once
#include <vector>
#include <list>

class Ennemy;
class Object;
class ICollider;
class HUD;
class Player;

namespace Main
{
	extern std::list<Object*> Objects;
	extern std::list<ICollider*> CollidingObjects;

	enum GameState
	{
		Playing,
		GameOver
	};

	extern Ennemy* ennemy;
	extern GameState gameState;
	extern HUD* _HUD;
	extern Player* player;
	extern float timeElapsed;

	Ennemy* SpawnDeathZone();
	void InitAllObjects();
	//extern float timeSpawn;
	//
	extern std::vector<float> posObt;
	//extern std::vector<Object*> listObt;

	extern float widthEcran;
	extern float heightEcran;

	//Auto move back
	extern float getCameraSpeed();

	//extern void spawnObt(float deltaTime, float timeSpawn, std::vector<float> posObt, std::vector<Object*> listObt);
	extern void spawnBlocks(float deltaTime);
	extern void DeleteTwoFirtsBlocks();

	extern void DeleteAllBlocks();
	extern void GameOverLogic();
	extern void InitGame();
};
