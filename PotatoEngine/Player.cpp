#include "Player.h"
#include "GameResources.h"

Player::Player()
{	
	auto* idle = new AnimatedSprite{
		textureManager.get("knight_idle"),
		6.f,
		6,
		1,
		1.f / 12.f,
		true
	};
	auto* run = new AnimatedSprite{
		textureManager.get("knight_run"),
		6.f,
		6,
		1,
		1.f / 12.f,
		true
	};
	animations.add("idle", idle);
	animations.add("run", run);
}

void Player::update(float delta)
{
	animations.set("idle");

	if (IsKeyDown(KEY_SPACE))
	{
		animations.set("run");
	}

	animations.update(delta);
}

void Player::draw()
{
	animations.draw();
}