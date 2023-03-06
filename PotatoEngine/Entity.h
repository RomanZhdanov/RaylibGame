#pragma once
#include "AnimationManager.h"

class Entity
{
public:
	virtual void update(float delta);
	virtual void draw();
	virtual void setPosition(Vector2 pos) { position = pos; }
	void undoMovement();
protected:
	float speed{};
	Vector2 position{};
	Vector2 positionLastFrame{};
	Vector2 velocity{};
	AnimationManager animations{};
};