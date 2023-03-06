#include "Player.h"
#include "GameResources.h"
#include "raymath.h"

Player::Player()
{	
	auto* player = new AnimatedSprite{
		textureManager.get("player"),
		4.f,
		60,
		1
	};

	speed = 400.f;
	float animationSpeed = 1.f / 12.f;
	animations.add("idle", new Animation(player, 59, 59, animationSpeed, true));
	animations.add("run_right", new Animation(player, 0, 5, animationSpeed, true));
	animations.add("run_up", new Animation(player, 6, 11, animationSpeed, true));
	animations.add("run_left", new Animation(player, 12, 17, animationSpeed, true));
	animations.add("run_down", new Animation(player, 18, 23, animationSpeed, true));
}

void Player::update(float delta)
{
	if (IsKeyDown(KEY_A)) velocity.x -= 1.0;
	if (IsKeyDown(KEY_D)) velocity.x += 1.0;
	if (IsKeyDown(KEY_W)) velocity.y -= 1.0;
	if (IsKeyDown(KEY_S)) velocity.y += 1.0;

	Entity::update(delta);
}