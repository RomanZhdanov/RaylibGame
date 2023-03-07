#pragma once
#include "Animation.h"
#include <map>

class AnimationManager
{
public:
	void update(float delta);
	void draw();
	void set(const char* anim);
	void add(const char* animName, Animation* animation);
	void setPosition(Vector2 position);
	void setRight();
	void setLeft();
	void reset() { activeAnimation->reset(); }
	bool isFinished() { return activeAnimation->isFinished(); }
	float getWidth() { return activeAnimation->width; }
	float getHeight() { return activeAnimation->height; }
private:
	std::map<const char*, Animation*> animations{};
	Animation* activeAnimation{};
};