#pragma once
#include "AnimatedSprite.h"
#include <map>

class AnimationManager
{
public:
	void update(float delta);
	void draw();
	void set(const char* anim);
	void add(const char* animName, AnimatedSprite* animation);
private:
	std::map<const char*, AnimatedSprite*> animations{};
	AnimatedSprite* activeAnimation{};
};