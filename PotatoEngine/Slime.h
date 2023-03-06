#pragma once
#include "Enemy.h"

class Slime : public Enemy
{
public:
	Slime();
	Enemy* Clone() const override {
		return new Slime(*this);
	}
};