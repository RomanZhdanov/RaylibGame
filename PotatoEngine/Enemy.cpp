#include "Enemy.h"

void Enemy::update(float delta)
{
	if (isAlive)
	{
		Entity::update(delta);

		if (target->getState() == PlayerState::ATTACK)
		{
			if (CheckCollisionRecs(collisionRec, target->getHitbox()))
			{
				isAlive = false;
			}
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