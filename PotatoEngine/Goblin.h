#pragma once
#include "Enemy.h"

class Goblin : public Enemy
{
public:
	Goblin();
	Enemy* Clone() const override {
		return new Goblin(*this);
	}
};