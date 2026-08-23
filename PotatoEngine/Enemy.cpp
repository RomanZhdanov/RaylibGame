#include "Enemy.h"
#include "raymath.h"

void Enemy::update(float delta)
{
	if (!isAlive) return;
	velocity = Vector2Subtract(target->getPosition(), getPosition());
	Entity::update(delta);

	if (CheckCollisionRecs(collisionRec, target->getCollisionRec()))
	{
		if (!target->isHurting())
			target->takeDamage();
		
		undoMovement();
	}

	if (target->getState() == PlayerState::ATTACK)
	{
		if (CheckCollisionRecs(collisionRec, target->getHitbox()))
		{
			isAlive = false;
			target->addScore(points);
		}		
	}

	if (collisionRecVisible)
	{
		DrawRectangleLines(
			collisionRec.x,
			collisionRec.y,
			collisionRec.width,
			collisionRec.height,
			BLUE
		);
	}
}