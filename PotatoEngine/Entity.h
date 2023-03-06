#pragma once
#include "AnimationManager.h"
#include "WindowDimensions.h"

class Entity
{
public:
	virtual void update(float delta);
	virtual void draw();
	virtual void setPosition(Vector2 pos) { position = pos; }
	virtual void setWindow(WindowDimensions win) { window = win; }
protected:
	float speed{};
	Vector2 position{};
	Vector2 positionLastFrame{};
	Vector2 velocity{};
	AnimationManager animations{};
	WindowDimensions window{};
	void undoMovement();
};