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
		
	float padding{ 1.f };

	float width = animations.getWidth() * padding;
	float height = animations.getHeight() * padding;

	collisionRec = {
		position.x,
		position.y,
		width,
		height
	};

	if (collisionRec.x < 0.f ||
		collisionRec.y < 0.f ||
		collisionRec.x > window.width ||
		collisionRec.y > window.height)
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