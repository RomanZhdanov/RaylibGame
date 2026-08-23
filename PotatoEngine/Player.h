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
	void takeDamage() { livesLeft -= 1; hurting = hurtTimeout; }
	void reset() { livesLeft = 4; hurting = 0.f; score = 0; position = Vector2{}; direction = Vector2{}; state = PlayerState::MOVE; }
	PlayerState getState() { return state; }
	void addScore(int value) { score += value; }
	int getScore() { return score; }
	int getLives() { return livesLeft; }
	bool isHurting() { return hurting > 0.f; }
	bool isAlive() { return livesLeft > 0; }
private:
	int score{ 0 };
	int livesLeft{ 4 };
	float hurtTimeout{ 2.f };
	float hurting{ 0.f };
	bool hitboxRecVisible{ false };
	void move(float delta);
	void attack(float delta);
	Rectangle hitbox{};
	PlayerState state{ PlayerState::MOVE };
};