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
	Rectangle getHitbox() { return hitbox; }
	virtual void update(float delta) override;
private:
	void move(float delta);
	void attack(float delta);
	Rectangle hitbox{};
	PlayerState state{ PlayerState::MOVE };
};