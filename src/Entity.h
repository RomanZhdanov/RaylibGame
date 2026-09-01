#pragma once
#include "AnimationManager.h"
#include "WindowDimensions.h"

class Entity
{
public:
    Entity() = default;
    virtual ~Entity() {}
	virtual void update(float delta);
	virtual void draw();
	virtual void setPosition(Vector2 pos) { position = pos; }
	virtual void setWindow(WindowDimensions win) { window = win; }
	void showCollisionRec(bool value) { collisionRecVisible = value; }
	Vector2 getPosition() { return Vector2{ position.x + animations.getWidth() / 2, position.y + animations.getHeight() / 2 }; }
	Rectangle getCollisionRec() { return collisionRec; }
	bool isAlive{ true };
protected:
    Entity(const Entity& e) :
            isAlive(e.isAlive),
            collisionRecVisible(e.collisionRecVisible),
            speed(e.speed),
            position(e.position),
            positionLastFrame(e.positionLastFrame),
            velocity(e.velocity),
            direction(e.direction),
            collisionRec(e.collisionRec),
            window(e.window) {}
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
