#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(Texture2D txtre, float scl, int framesX, int framesY, float speed, bool looping) :
	Sprite(txtre, scl),
	framesX(framesX),
	framesY(framesY),
	looping(looping),
	speed(speed)
{
	frameWidth = texture.width / framesX;
	frameHeight = texture.height / framesY;
}

void AnimatedSprite::update(float delta)
{
	if (currentFrame == getFramesCount() - 1 &&
		looping == false)
	{
		finished = true;
		return;
	}

	currentFrameTime -= delta;

	if (currentFrameTime < 0)
	{
		currentFrame++;
		currentFrameTime = speed;
	}
}

void AnimatedSprite::draw()
{
	Rectangle source{ currentFrame * frameWidth, currentFrame * frameHeight, frameWidth, frameHeight };
	Rectangle dest{ position.x, position.y, scale * frameWidth, scale * frameHeight };

	DrawTexturePro(texture, source, dest, Vector2{}, rotation, color);
}