#include "Main.h"
#include <vector>
#include <iostream>
#include "Object.h"
//Edit
#include "Block.h"

std::list<Object*> Main::Objects;
std::list<ICollider*> Main::CollidingObjects;

float timeSpawn = 0.0f;
float timeSpawn2 = 0.0f;

//float widthEcran = sf::VideoMode::getDesktopMode().width;
//float heightEcran = sf::VideoMode::getDesktopMode().height;

float Main::widthEcran;
std::vector<float> Main::posObt;
std::list<Block*> listObt;

bool verif = false;

void Main::spawnObt(float deltaTime)
{
    timeSpawn += deltaTime;
    timeSpawn2 += deltaTime;

	if (timeSpawn > 2)
	{
        std::vector<float> copiePosObjt = posObt;

        for (int i = 0; i < 2; i++)
        {
            int index = rand() % copiePosObjt.size();

            Block* object = new Block();
            object->shape->setPosition(widthEcran, copiePosObjt[index]);
            listObt.push_back(object);
            copiePosObjt.erase(copiePosObjt.begin() + index);
        }

        timeSpawn = 0;
	}

    if (timeSpawn2 > 4)
    {
        DeleteObt();
        timeSpawn2 = 0;
    }
}


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

void Main::DeleteAllObt()
{
    Block* block;
    for (int i = 0; i < listObt.size(); i++)
    {
        block = listObt.front();
        listObt.pop_front();
        block->Destroy();
    }
    listObt.clear();
}

void Main::EnnemySpawner()
{
    Object* ennemies[3] = { nullptr };
    for (int i = 0; i < 3; ++i) {
        Object* ennemy = new Object(Object::ShapeType::Circle, true);
		dynamic_cast<sf::CircleShape*>(ennemy->shape)->setFillColor(sf::Color::Red);
        ennemies[i] = ennemy;
    }
    std::cout << "Ennemies created" << std::endl;
}

void Main::DeleteAllEnemies() {
}


//Main::DeleteAllObt()
void Main::InitAllObjects() {
    for (auto it = Main::Objects.begin(); it != Main::Objects.end(); ) {

        //Supp tous les enemies
        if (typeid(**it) == typeid(Block)) { 
            std::cout << " Block on supp." << std::endl;
            //Check si vrmt supp ou jst n apparait plus
            it = Main::Objects.erase(it);  
        }

        // init etat de tout autre objet
        else {
            (*it)->Init();
            ++it;
        }
    }
}