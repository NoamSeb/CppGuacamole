#include "Main.h"

#include <vector>
#include <iostream>
#include "Object.h"
#include "Ennemy.h"
#include "HUD.h"
#include "Block.h"
#include "Player.h"

//Edit

std::list<Object*> Main::Objects;
std::list<ICollider*> Main::CollidingObjects;

Player* Main::player;
HUD* Main::_HUD;
float Main::timeElapsed;

float timeSpawn = 0.0f;
float timeDestroy = 0.0f;
float attenteDestroy = 16.0f;
Main::GameState Main::gameState = Main::GameState::GameOver;

//float widthEcran = sf::VideoMode::getDesktopMode().width;
//float heightEcran = sf::VideoMode::getDesktopMode().height;

float Main::widthEcran;
float Main::heightEcran;
std::vector<float> Main::posObt;
std::list<Block*> listObt;

bool verif = false;

void Main::spawnObt(float deltaTime)
{
    timeSpawn += deltaTime;
    timeDestroy += deltaTime;

	if (timeSpawn > 4)
	{
        std::vector<float> copiePosObjt = posObt;

        for (int i = 0; i < 2; i++)
        {
            int index = rand() % copiePosObjt.size();

            Block* object = new Block();
            object->SetPosition(widthEcran, copiePosObjt[index]);
            dynamic_cast<sf::RectangleShape*>(object->shape)->setSize(sf::Vector2f(150, heightEcran / 3));
            listObt.push_back(object);
            copiePosObjt.erase(copiePosObjt.begin() + index);
        }

        timeSpawn = 0;
	}

    if (timeDestroy > attenteDestroy)
    {
        Main::DeleteTwoFirtsBlocks();
        timeDestroy = 0;
        attenteDestroy = 6.0f;
    }
}

//Delet two first blocks
void Main::DeleteTwoFirtsBlocks()
{
    Block* block;
    for (int i = 0; i < 2; i++)
    {
        block = listObt.front();
        listObt.pop_front();
        block->Destroy();
    }
    //listObt.clear();
}

void Main::DeleteAllBlocks()
{
    //Init Blocks values
    timeSpawn = 0.0f;
    timeDestroy = 0.0f;
    attenteDestroy = 16.0f;

    //Delete all Blocks
    for (auto it = listObt.begin(); it != listObt.end(); ) {
        delete* it;
        it = listObt.erase(it);

    }
    listObt.clear();
}

Ennemy* Main::SpawnDeathZone()
{
    Ennemy* ennemy = new Ennemy(100, heightEcran);
    ennemy->shape->setFillColor(sf::Color::Red);
    std::cout << "Ennemies created" << std::endl;
    return ennemy;
}


void Main::InitAllObjects() {
    for (auto it = Main::Objects.begin(); it != Main::Objects.end(); ) {
        //Pas d'initialistation pr les blocks qui vont etre supp par la suite
        if (typeid(**it) != typeid(Block)) { 
            (*it)->Init();
        }
        it++;
    }
}

void Main::GameOverLogic()
{
    std::cout << "Game Over" << std::endl;
    //Delete all blocks
    DeleteAllBlocks();
    Main::CollidingObjects.clear();
    Main::Objects.clear();
    //Delete all objects
    Main::gameState = Main::GameState::GameOver;
}

void Main::InitGame() {
    std::cout << "Init Game" << std::endl;
    player = new Player(300.0f, 250.0f);
    SpawnDeathZone();
    DeleteAllBlocks();
    _HUD = HUD::getInstance();
    _HUD->LoadFont(); // pr tous les texts
    timeElapsed = 0;
}
