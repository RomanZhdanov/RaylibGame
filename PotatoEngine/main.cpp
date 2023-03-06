#include "raylib.h"
#include "Player.h"
#include "GameResources.h"
#include "EnemyManager.h"
#include <vector>

int main()
{
	int windowWidth{ 800 };
	int windowHeight{ 600 };

	InitWindow(windowWidth, windowHeight, "Potato");
	
	LoadTextures();

	EnemyManager enemies;

	enemies.create("goblin", Vector2{250.f, 450.f});
	enemies.create("slime", Vector2{500.f, 450.f});

	Player knight;

	while (!WindowShouldClose())
	{
		float delta = GetFrameTime();
		knight.update(delta);
		enemies.update(delta);

		BeginDrawing();

		ClearBackground(WHITE);

		knight.draw();
		enemies.draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}