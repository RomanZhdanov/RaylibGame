#pragma once
#include "Enemy.h"

class Slime : public Enemy
{
public:
	Slime();
	virtual void loadAnimations() override;
	Enemy* Clone() const override {
		return new Slime(*this);
	}
};