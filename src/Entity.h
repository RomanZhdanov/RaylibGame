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
	virtual void takeDamage(int dmg) { health -= dmg; };
	void showCollisionRec(bool value) { collisionRecVisible = value; }
	int getHealth() { return health; }
	int getDamage() { return damage; }
	Vector2 getPosition() { return Vector2{ position.x + animations.getWidth() / 2, position.y + animations.getHeight() / 2 }; }
	Rectangle getCollisionRec() { return collisionRec; }
	bool isAlive() { return health > 0; };
protected:
    Entity(const Entity& e) :
            health(e.health),
            speed(e.speed),
            damage(e.damage),
            collisionRecVisible(e.collisionRecVisible),
            position(e.position),
            positionLastFrame(e.positionLastFrame),
            velocity(e.velocity),
            direction(e.direction),
            collisionRec(e.collisionRec),
            window(e.window) {}
	int health{};
	float speed{};
	int damage {};
	bool collisionRecVisible{ false };
	Vector2 position{};
	Vector2 positionLastFrame{};
	Vector2 velocity{};
	Vector2 direction{};
	Rectangle collisionRec{};
	AnimationManager animations{};
	WindowDimensions window{};
	void undoMovement();
};
