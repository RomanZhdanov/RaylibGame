#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	virtual void update(float delta) override;
private:
};