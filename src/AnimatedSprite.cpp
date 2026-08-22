#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(Texture2D* txtre, float scl, int framesX, int framesY) :
	Sprite(txtre, scl),
	framesX(framesX),
	framesY(framesY)
{
	frameWidth = texture->width / framesX;
	frameHeight = texture->height / framesY;
}

void AnimatedSprite::drawFrame(int frame)
{
	Rectangle source{ frame * frameWidth, frame * frameHeight, rightleft * frameWidth, frameHeight };
	Rectangle dest{ position.x, position.y, scale * frameWidth, scale * frameHeight };

	DrawTexturePro(*texture, source, dest, Vector2{}, rotation, color);
}