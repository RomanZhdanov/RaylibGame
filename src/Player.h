#pragma once
#include "Entity.h"
#include "InputSource.h"

enum class PlayerState {
	MOVE,
	ROLL,
	ATTACK
};

class Player : public Entity
{
public:
	Player();
	void setInput(InputSource* _input) { input = _input; }
	Rectangle getHitbox() { return hitbox; }
	Rectangle getHurtbox() { return hurtbox; }
	virtual void update(float delta) override;
	void draw() override;
	void showHitboxRec(bool value) { hitboxRecVisible = value; }
	void showHurtboxRec(bool value) { hurtboxRecVisible = value; }
	void takeDamage() { livesLeft -= 1; hurting = hurtTimeout; }
	void reset() { livesLeft = 4; hurting = 0.f; score = 0; position = Vector2{}; direction = Vector2{}; state = PlayerState::MOVE; }
	PlayerState getState() { return state; }
	void addScore(int value) { score += value; }
	int getScore() { return score; }
	int getLives() { return livesLeft; }
	bool isHurting() { return hurting > 0.f; }
	bool isAlive() { return livesLeft > 0; }
private:
	InputSource* input{ };
	int score{ 0 };
	int livesLeft{ 4 };
	float hurtTimeout{ 2.f };
	float hurting{ 0.f };
	float rollSpeed{ };
	bool hitboxRecVisible{ false };
	bool hurtboxRecVisible{ false };
	void move(float delta);
	void roll(float delta);
	void attack(float delta);
	void setRecs();
	void checkBorders();
	void updateInput();
	Rectangle hitbox{};
	Rectangle hurtbox{};
	PlayerState state{ PlayerState::MOVE };
};
