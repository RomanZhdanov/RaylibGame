#pragma once
#include "AnimatedSprite.h"
#include <map>
#include <string>

class Player
{
public:
	Player();
	void update(float delta);
	void draw();
private:
	std::map<std::string,AnimatedSprite*> animations;
	AnimatedSprite* activeAnimation{};
};