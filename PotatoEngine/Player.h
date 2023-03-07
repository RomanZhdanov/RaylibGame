#pragma once
#include "Entity.h"

enum class PlayerState {
	MOVE,
	ATTACK
};

class Player : public Entity
{
public:
	Player();
	virtual void update(float delta) override;
private:
	void move(float delta);
	void attack(float delta);
	PlayerState state{ PlayerState::MOVE };
};