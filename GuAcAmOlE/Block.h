#pragma once
#include"Object.h"


class Block : public Object
{
public:
	virtual void Tick(float DeltaTime) override;
};