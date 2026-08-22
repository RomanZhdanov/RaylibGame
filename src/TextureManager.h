#pragma once
#include <map>
#include <string>
#include "raylib.h"

class TextureManager
{
public:
	~TextureManager();
	void loadTexture(const char* textureId, const char* path);
	Texture2D* get(const char* textureId);
private:
	std::map<std::string, Texture2D> textureStorage{};
};
