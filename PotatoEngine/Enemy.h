#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	Enemy() {}
	virtual void update(float delta) override;
	virtual Enemy* Clone() const = 0;
};