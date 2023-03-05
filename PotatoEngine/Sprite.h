#pragma once
#include "raylib.h"

class Sprite
{
public:
	Sprite(Texture2D texture, Vector2 position, float scale);
	Vector2 getPosition() { return getCenter(); }
	void setScale(float scl) { scale = scl; }
	void setColor(Color clr) { color = clr; }
	void setRotation(float rtn) { rotation = rtn; }
	void draw();
protected:
	Texture2D texture{};
	Vector2 position{};
	float scale{};
	float rotation{};
	Color color{};
private:
	Vector2 getCenter();
};