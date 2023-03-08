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
	Vector2 getPosition() { return position; }
	Rectangle getCollisionRec() { return collisionRec; }
protected:
	bool isAlive{ true };
	float speed{};
	Vector2 position{};
	Vector2 positionLastFrame{};
	Vector2 velocity{};
	Rectangle collisionRec{};
	AnimationManager animations{};
	WindowDimensions window{};
	void undoMovement();
};