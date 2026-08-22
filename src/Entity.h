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
	void showCollisionRec(bool value) { collisionRecVisible = value; }
	Vector2 getPosition() { return Vector2{ position.x + animations.getWidth() / 2, position.y + animations.getHeight() / 2 }; }
	Rectangle getCollisionRec() { return collisionRec; }
protected:
	bool isAlive{ true };
	bool collisionRecVisible{ false };
	float speed{};
	Vector2 position{};
	Vector2 positionLastFrame{};
	Vector2 velocity{};
	Vector2 direction{};
	Rectangle collisionRec{};
	AnimationManager animations{};
	WindowDimensions window{};
	void undoMovement();
};