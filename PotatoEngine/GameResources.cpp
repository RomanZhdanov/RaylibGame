#include "GameResources.h"

TextureManager textureManager{};

void LoadTextures()
{
	textureManager.loadTexture("knight_idle", "assets/knight_idle_spritesheet.png");
	textureManager.loadTexture("knight_run", "assets/knight_run_spritesheet.png");
	textureManager.loadTexture("goblin_idle", "assets/goblin_idle_spritesheet.png");
	textureManager.loadTexture("goblin_run", "assets/goblin_run_spritesheet.png");
	textureManager.loadTexture("slime_idle", "assets/slime_idle_spritesheet.png");
	textureManager.loadTexture("slime_run", "assets/slime_run_spritesheet.png");
	textureManager.loadTexture("bush", "assets/bush.png");
}