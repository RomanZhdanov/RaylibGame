#pragma once
#include <map>
#include "raylib.h"

class TextureManager
{
public:
	void loadTexture(const char* textureId, const char* path);
	Texture2D* get(const char* textureId);
private:
	std::map<const char*, Texture2D> textureStorage{};
};