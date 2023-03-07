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
	Rectangle getCollisionRec() { return collisionRec; }
	virtual void update(float delta) override;
private:
	void move(float delta);
	void attack(float delta);
	Rectangle collisionRec{};
	Rectangle hitbox{};
	PlayerState state{ PlayerState::MOVE };
};