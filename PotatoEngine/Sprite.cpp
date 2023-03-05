#include "Sprite.h"
#include "raylib.h"

Sprite::Sprite()
{

}

Sprite::Sprite(Texture2D texture, float scale) :
	texture(texture),
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