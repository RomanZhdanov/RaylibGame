#pragma once
#include "AnimatedSprite.h"

class Animation
{
public:
	Animation(AnimatedSprite* sprite, int startFrame, int endFrame, float speed, bool looping);
	void update(float delta);
	void draw();
	AnimatedSprite* sprite;
private:
	int startFrame{};
	int endFrame{};
	int currentFrame{};
	bool looping{};
	bool finished{};
	float speed{};
	float currentFrameTime{};
};