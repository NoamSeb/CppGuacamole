#include "Main.h"
#include <vector>
#include "Object.h"

std::list<Object*> Main::Objects;

float timeSpawn = 0.0f;

std::vector<float> posObt = { 0.0f, 300.0f, 600.0f };
std::vector<Object*> listObt;

void Main::spawnObt(float deltaTime)
{
    timeSpawn += deltaTime;
	if (timeSpawn > 3)
	{
        for (int i = 0; i < listObt.size(); i++)
        {
            listObt[i]->Destroy();
        }
        listObt.clear();

        std::vector<float> copiePosObjt = posObt;

        for (int i = 0; i < 2; i++)
        {
            int index = rand() % copiePosObjt.size();

            Object* object = new Object(Object::ShapeType::Rectangle, true);
            object->shape->setPosition(copiePosObjt[index], 0.0f);
            listObt.push_back(object);
            copiePosObjt.erase(copiePosObjt.begin() + index);
        }

        timeSpawn = 0;
	}
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


void Main::InitAllObjects() {
    for (auto it = Main::Objects.begin(); it != Main::Objects.end(); ) {

        //Supp tous les enemies
        if (typeid(**it) != typeid(Player)) { // plus tard == id Ennemy
            std::cout << " Enemy on supp." << std::endl;
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
