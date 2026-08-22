#pragma once
#include "Enemy.h"

class Goblin : public Enemy
{
public:
	Goblin();
	virtual void loadAnimations() override;
	Enemy* Clone() const override {
		return new Goblin(*this);
	}
};