#pragma once
#include "AnimationManager.h"

class Entity
{
public:
	virtual void update(float delta);
	virtual void draw();
protected:
	AnimationManager animations{};
};