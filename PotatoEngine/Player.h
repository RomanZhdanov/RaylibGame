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
	int score;
	Rectangle getHitbox() { return hitbox; }
	virtual void update(float delta) override;
	PlayerState getState() { return state; }
private:
	void move(float delta);
	void attack(float delta);
	Rectangle hitbox{};
	PlayerState state{ PlayerState::MOVE };
};