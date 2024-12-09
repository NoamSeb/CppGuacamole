#pragma once
#include"Object.h"


class Block : public Object
{
public:

	Block() : Object(Rectangle, true) {}
	virtual void Tick(float DeltaTime) override; 
};