#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy() {}
	virtual Enemy* Clone() const = 0;
};