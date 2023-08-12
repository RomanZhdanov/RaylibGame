#include "Enemy.h"
#include "raymath.h"

void Enemy::update(float delta)
{
	if (!isAlive) return;
	velocity = Vector2Subtract(target->getPosition(), getPosition());
	Entity::update(delta);

	if (target->getState() == PlayerState::ATTACK)
	{
		if (CheckCollisionRecs(collisionRec, target->getHitbox()))
		{
			isAlive = false;
			target->AddScore(1);
		}
	}

	DrawRectangleLines(
		collisionRec.x,
		collisionRec.y,
		collisionRec.width,
		collisionRec.height,
		BLUE
	);
}