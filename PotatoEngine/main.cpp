#include "raylib.h"
#include "Player.h"
#include "GameResources.h"
#include "EnemyManager.h"
#include <vector>
#include "WindowDimensions.h"

int main()
{
	WindowDimensions window{ 1200, 800 };

	InitWindow(window.width, window.height, "Potato");
	
	LoadTextures();

	Player knight;
	knight.setWindow(window);

	EnemyManager enemies;
	enemies.create("goblin", Vector2{250.f, 450.f}, &knight, window);
	enemies.create("slime", Vector2{500.f, 450.f}, &knight, window);

	while (!WindowShouldClose())
	{
		float delta = GetFrameTime();
		knight.update(delta);
		enemies.update(delta);

		BeginDrawing();

		ClearBackground(LIGHTGRAY);

		knight.draw();
		enemies.draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}