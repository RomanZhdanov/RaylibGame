#include "Entity.h"

void Entity::update(float delta)
{
	animations.update(delta);
}

void Entity::draw()
{
	animations.draw();
}

void Entity::setPosition(Vector2 pos)
{
	animations.setPosition(pos);
}