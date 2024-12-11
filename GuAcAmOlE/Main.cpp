#include "Main.h"
#include <vector>
#include <iostream>
#include "Object.h"
#include "Ennemy.h"
//Edit
#include "Block.h"

std::list<Object*> Main::Objects;
std::list<ICollider*> Main::CollidingObjects;

float timeSpawn = 0.0f;
float timeDestroy = 0.0f;
float attenteDestroy = 16.0f;

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
    timeSpawn = 0.0f;
    timeDestroy = 0.0f;
    attenteDestroy = 16.0f;


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