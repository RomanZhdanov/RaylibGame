#include "Entity.h"
#include "raymath.h"

void Entity::update(float delta)
{
	positionLastFrame = position;

	if (Vector2Length(velocity) != 0.0)
	{
		position = Vector2Add(position, Vector2Scale(Vector2Normalize(velocity), speed * delta));		
	}
	else
	{
		animations.set("idle");
	}
	velocity = {};

	if (position.x < 0.f ||
		position.y < 0.f ||
		position.x > window.width ||
		position.y > window.height)
	{
		undoMovement();
	}

	animations.setPosition(position);
	animations.update(delta);
}

void Entity::draw()
{
	animations.draw();
}

void Entity::undoMovement()
{
	position = positionLastFrame;
}