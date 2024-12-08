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
