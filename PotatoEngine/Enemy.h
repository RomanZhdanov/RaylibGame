#pragma once
#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
public:
	Enemy() {}
	void setTarget(Player* player) { target = player; }
	virtual void update(float delta) override;
	virtual Enemy* Clone() const = 0;
protected:
	Player* target;
};