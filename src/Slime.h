#pragma once
#include "Enemy.h"

class Slime : public Enemy
{
public:
	Slime(int _health, int _damage, float _speed, int _points, float _scale, Color _color);
	virtual void loadAnimations() override;
	Enemy* Clone() const override {
		return new Slime(*this);
	}
};
