#include "GameResources.h"

TextureManager textureManager{};

void LoadTextures()
{
	textureManager.loadTexture("knight_idle", "assets/knight_idle_spritesheet.png");
	textureManager.loadTexture("knight_run", "assets/knight_run_spritesheet.png");
	textureManager.loadTexture("bush", "assets/bush.png");
}