#pragma once
#include "Sprite.h"

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite(Texture2D* texture, float scale, int framesX, int framesY, float speed, bool looping);
	void update(float delta);
	virtual void draw() override;
	int getFramesCount() const { return framesX * framesY; }
private:
	int framesX{ 1 };
	int framesY{ 1 };
	int currentFrame{ 0 };
	bool looping{};
	bool finished{};
	float speed{};
	float currentFrameTime{};
	float frameWidth{};
	float frameHeight{};
};