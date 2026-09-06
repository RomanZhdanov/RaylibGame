#pragma once
#include <memory>
#include "AnimatedSprite.h"

class Animation
{
public:
	Animation(std::shared_ptr<AnimatedSprite> sprite, int startFrame, int endFrame, float speed, bool looping);
	void update(float delta);
	void draw();
	void reset() { currentFrame = startFrame; finished = false; }
	bool isFinished() { return finished; }
	std::shared_ptr<AnimatedSprite> sprite;
	float width{};
	float height{};
private:
	int startFrame{};
	int endFrame{};
	int currentFrame{};
	bool looping{};
	bool finished{};
	float speed{};
	float currentFrameTime{};
};
