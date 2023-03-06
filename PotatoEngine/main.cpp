#include "raylib.h"
#include "Sprite.h"
#include "Player.h"
#include "GameResources.h"

TextureManager textureManager{};

void LoadTextures()
{
	textureManager.loadTexture("knight_idle", "assets/knight_idle_spritesheet.png");
	textureManager.loadTexture("knight_run", "assets/knight_run_spritesheet.png");
	textureManager.loadTexture("bush", "assets/bush.png");
}

int main()
{
	int windowWidth{ 800 };
	int windowHeight{ 600 };

	InitWindow(windowWidth, windowHeight, "Potato");
	LoadTextures();

	Sprite bush{
		textureManager.get("bush"),
		1.f
	};

	bush.setPosition(Vector2{});

	Player knight;

	while (!WindowShouldClose())
	{
		float delta = GetFrameTime();
		knight.update(delta);

		BeginDrawing();

		ClearBackground(WHITE);

		bush.draw();
		knight.draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}