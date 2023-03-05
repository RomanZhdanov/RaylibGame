#pragma once
#include "AnimatedSprite.h"
#include <vector>

class Player
{
public:
	Player();
	void update(float delta);
	void draw();
private:
	std::vector<AnimatedSprite> animations;
	AnimatedSprite* activeAnimation{};
};