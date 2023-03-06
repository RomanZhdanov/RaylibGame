#include "Player.h"

Player::Player()
{	
	animations.insert(std::make_pair("idle", new AnimatedSprite{
		LoadTexture("assets/knight_idle_spritesheet.png"),
		6.f,
		6,
		1,
		1.f / 12.f,
		true
	}));
	animations.insert(std::make_pair("run", new AnimatedSprite{
		LoadTexture("assets/knight_run_spritesheet.png"),
		6.f,
		6,
		1,
		1.f / 12.f,
		true
	}));
}

void Player::update(float delta)
{
	activeAnimation = animations["idle"];

	if (IsKeyDown(KEY_SPACE))
	{
		activeAnimation = animations["run"];
	}

	activeAnimation->update(delta);
}

void Player::draw()
{
	activeAnimation->draw();
}