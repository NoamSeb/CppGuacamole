#include "Main.h"
#include <vector>
#include <iostream>
#include "Object.h"
#include "Ennemy.h"
//Edit

std::list<Object*> Main::Objects;
std::list<ICollider*> Main::CollidingObjects;

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
            listObt.push_back(object);
            copiePosObjt.erase(copiePosObjt.begin() + index);
        }

        timeSpawn = 0;
	}

    if (timeDestroy > attenteDestroy)
    {
        DeleteObt();
        timeDestroy = 0;
        attenteDestroy = 6.0f;
    }
}

//Delet two first blocks
void Main::DeleteObt() 
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

void Main::EnnemySpawner()
{
    Ennemy* ennemies[3] = { nullptr };
    for (int i = 0; i < 3; ++i) {
        Ennemy* ennemy = new Ennemy(Ennemy::ShapeType::Rectangle, true);
        ennemy->shape->setFillColor(sf::Color::Red);
        //ennemy->shape->setSize;
        dynamic_cast<sf::RectangleShape*>(ennemy->shape)->setSize(sf::Vector2f(100, heightEcran));
        ennemies[i] = ennemy;
    }
    std::cout << "Ennemies created" << std::endl;
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
