#include "Player.h"

Player::Player()
{	
	animations.push_back(AnimatedSprite{
		LoadTexture("assets/knight_idle_spritesheet.png"),
		6.f,
		6,
		1,
		1.f / 12.f,
		true
	});
	animations.push_back(AnimatedSprite{
		LoadTexture("assets/knight_run_spritesheet.png"),
		6.f,
		6,
		1,
		1.f / 12.f,
		true
	});
}

void Player::update(float delta)
{
	activeAnimation = &animations[0];

	if (IsKeyDown(KEY_SPACE))
	{
		activeAnimation = &animations[1];
	}

	activeAnimation->update(delta);
}

void Player::draw()
{
	activeAnimation->draw();
}