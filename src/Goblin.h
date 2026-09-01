#pragma once
#include "Enemy.h"

class Goblin : public Enemy
{
public:
	Goblin(int _health, int _damage, float _speed, int _points);
	virtual void loadAnimations() override;
	Enemy* Clone() const override {
		return new Goblin(*this);
	}
};
