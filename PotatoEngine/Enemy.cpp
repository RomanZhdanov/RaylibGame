#include "Enemy.h"

void Enemy::update(float delta)
{
	Entity::update(delta);

	DrawRectangleLines(
		collisionRec.x,
		collisionRec.y,
		collisionRec.width,
		collisionRec.height,
		BLUE
	);
}