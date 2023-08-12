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
	void showHitboxRec(bool value) { hitboxRecVisible = value; }
	PlayerState getState() { return state; }
	void addScore(int value) { score += value; }
	int getScore() { return score; }
	int getLives() { return lives; }
private:
	int score{ 0 };
	int lives{ 4 };
	bool hitboxRecVisible{ false };
	void move(float delta);
	void attack(float delta);
	Rectangle hitbox{};
	PlayerState state{ PlayerState::MOVE };
};