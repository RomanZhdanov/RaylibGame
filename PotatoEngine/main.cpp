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

	EnemyManager enemies;

	enemies.create("goblin", Vector2{250.f, 450.f});
	enemies.create("slime", Vector2{500.f, 450.f});

	Player knight;
	knight.setWindow(window);

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