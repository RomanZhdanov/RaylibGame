#include "Enemy.h"
#include "raymath.h"

void Enemy::update(float delta)
{
	if (!isAlive()) return;

	if (attacked) {
	    velocity = {};
	} else {
	    velocity = Vector2Subtract(target->getPosition(), getPosition());
	}


	if (target->getState() == PlayerState::ATTACK)
	{
		if (!attacked && CheckCollisionRecs(collisionRec, target->getHitbox()))
		{
		    attacked = true;
		    takeDamage(target->getDamage());

			if (!isAlive())
			{
			    target->addScore(points);
			}
		}
	} else {
	    attacked = false;
	}

	Entity::update(delta);

	if (CheckCollisionRecs(collisionRec, target->getHurtbox()))
	{
		if (!target->isHurting() && target->getState() != PlayerState::ROLL)
			target->takeDamage(damage);

		undoMovement();
	}
}

void Enemy::draw()
{
	Entity::draw();

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
