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
	void showHitboxRec(bool value) { hitboxRecVisible = value; }
	PlayerState getState() { return state; }
	void AddScore(int value) { score += value; }
private:
	bool hitboxRecVisible{ false };
	void move(float delta);
	void attack(float delta);
	Rectangle hitbox{};
	PlayerState state{ PlayerState::MOVE };
};