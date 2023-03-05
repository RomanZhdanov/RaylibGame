#include "Sprite.h"
#include "raylib.h"

Sprite::Sprite(Texture2D texture, Vector2 position, float scale) :
	texture(texture),
	position(position),
	scale(scale)
{
	color = WHITE;
}

Vector2 Sprite::getCenter()
{
	float halfWidth = texture.width / 2;
	float halfHeight = texture.height / 2;

	return Vector2{
		position.x + halfWidth,
		position.y + halfHeight
	};
}

void Sprite::draw()
{
	DrawTextureEx(texture, position, rotation, scale, color);
}