#pragma once
#include "AnimationManager.h"

class Entity
{
public:
	virtual void update(float delta);
	virtual void draw();
	virtual void setPosition(Vector2 pos);
protected:
	AnimationManager animations{};
};