#include "Entity.h"

void Entity::update(float delta)
{
	animations.update(delta);
}

void Entity::draw()
{
	animations.draw();
}