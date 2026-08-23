#pragma once
#include "Sprite.h"

class AnimatedSprite : public Sprite
{
public:
	AnimatedSprite(Texture2D* texture, float scale, int framesX, int framesY);
	void drawFrame(int frame);
	int getFramesCount() const { return framesX * framesY; }
	void setRightLeft(float value) { rightleft = value; }
	float getWidth() { return frameWidth * scale; }
	float getHeight() { return frameHeight * scale; }
private:
	int framesX{ 1 };
	int framesY{ 1 };
	float frameWidth{};
	float frameHeight{};
	float rightleft{ 1.f };
};