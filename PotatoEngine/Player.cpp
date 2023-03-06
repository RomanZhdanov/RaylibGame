#include "Player.h"
#include "GameResources.h"
#include "raymath.h"

Player::Player()
{	
	auto* idle = new AnimatedSprite{
		textureManager.get("knight_idle"),
		6.f,
		6,
		1
	};
	auto* run = new AnimatedSprite{
		textureManager.get("knight_run"),
		6.f,
		6,
		1
	};

	speed = 400.f;
	animations.add("idle", new Animation(idle, 0, 5, 1.f / 12.f, true));
	animations.add("run", new Animation(run, 0, 5, 1.f / 12.f, true));
}

void Player::update(float delta)
{
	if (IsKeyDown(KEY_A)) velocity.x -= 1.0;
	if (IsKeyDown(KEY_D)) velocity.x += 1.0;
	if (IsKeyDown(KEY_W)) velocity.y -= 1.0;
	if (IsKeyDown(KEY_S)) velocity.y += 1.0;

	Entity::update(delta);
}