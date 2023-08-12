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

	float spawnTime{ 2.f };
	float currentSpawnTime{};
	Vector2 spawnPosition{
		window.width / 2,
		window.height
	};

	EnemyManager enemies;

	while (!WindowShouldClose())
	{
		float delta = GetFrameTime();

		currentSpawnTime -= delta;
		if (currentSpawnTime < 0)
		{
			currentSpawnTime = spawnTime;
			enemies.create("goblin", spawnPosition, &knight, window);
			enemies.create("slime", spawnPosition, &knight, window);
		}

		knight.update(delta);
		enemies.update(delta);

		BeginDrawing();

		ClearBackground(LIGHTGRAY);

		DrawText(TextFormat("Score: %i", knight.score), 10, 10, 20, LIME);

		/*knight.showHitboxRec(true);
		knight.showCollisionRec(true);
		enemies.showCollisionRec(true);*/

		knight.draw();
		enemies.draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}