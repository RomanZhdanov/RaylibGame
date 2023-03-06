#include "Animation.h"

Animation::Animation(AnimatedSprite* sprite, int startFrame, int endFrame, float speed, bool looping) :
	sprite(sprite),
	startFrame(startFrame),
	endFrame(endFrame),
	speed(speed),
	looping(looping)
{
	currentFrame = startFrame;
	currentFrameTime = speed;
}

void Animation::update(float delta)
{
	if (currentFrame == endFrame &&
		looping == false)
	{
		finished = true;
		return;
	}

	currentFrameTime -= delta;

	if (currentFrameTime < 0)
	{
		currentFrame == endFrame ? currentFrame = startFrame : currentFrame++;
		currentFrameTime = speed;
	}
}

void Animation::draw()
{
	sprite->drawFrame(currentFrame);
}