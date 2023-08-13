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

	Color hudColor = LIME;
	EnemyManager enemies;

	while (!WindowShouldClose())
	{
		float delta = GetFrameTime();		

		if (knight.isAlive())
		{
			currentSpawnTime -= delta;
			
			if (currentSpawnTime < 0)
			{
				currentSpawnTime = spawnTime;
				enemies.create("goblin", spawnPosition, &knight, window);
				enemies.create("slime", spawnPosition, &knight, window);
			}

			knight.update(delta);
			enemies.update(delta);
		}

		BeginDrawing();

		ClearBackground(LIGHTGRAY);

		DrawText(TextFormat("Lives: %i", knight.getLives()), 10, 10, 20, hudColor);
		DrawText(TextFormat("Score: %i", knight.getScore()), window.width - 200, 10, 20, hudColor);

		/*knight.showHitboxRec(true);
		knight.showCollisionRec(true);
		enemies.showCollisionRec(true);*/

		knight.draw();
		enemies.draw();

		if (!knight.isAlive())
		{
			const char* endGameText = "Game Over";
			int textWidth = MeasureText(endGameText, 60);
			DrawText(endGameText, window.width / 2 - textWidth / 2, window.height / 2 - 30, 60, RED);
		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}