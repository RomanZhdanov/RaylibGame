#include "raylib.h"
#include "Player.h"
#include "GameResources.h"
#include "EnemyManager.h"
#include <vector>
#include "WindowDimensions.h"
#include "Version.h"

int main()
{
	int gamepad = 0;

	WindowDimensions window{ 1200, 800 };

	InitWindow(window.width, window.height, "Killer Fox");

	LoadTextures();

	Player knight;
	knight.setWindow(window);
	knight.setGamepad(gamepad);

	float spawnTime{ 2.f };
	float currentSpawnTime{};
	Vector2 spawnPosition{
		window.width / 2.f,
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
		else
		{
			bool reset = false;

			if (IsGamepadAvailable(gamepad))
			{
				if (IsGamepadButtonPressed(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
				{
					reset = true;
				}
			}
			else if (IsKeyPressed(KEY_R))
			{
				reset = true;
			}

			if (reset)
			{
				knight.reset();
				enemies.deleteAll();
			}
		}

		BeginDrawing();

		ClearBackground(LIGHTGRAY);

		DrawText(TextFormat("Lives: %i", knight.getLives()), 10, 10, 20, hudColor);
		DrawText(TextFormat("Score: %i", knight.getScore()), window.width - 200, 10, 20, hudColor);
		DrawText(TextFormat("v%s", GAME_VERSION), 10, window.height - 20, 10, hudColor);

		/*knight.showHitboxRec(true);
		knight.showCollisionRec(true);
		enemies.showCollisionRec(true);*/

		knight.draw();
		enemies.draw();

		if (!knight.isAlive())
		{
			const char* gameOverText = "Game Over";
			const char* resetText{};

			if (IsGamepadAvailable(gamepad))
			{
				resetText = "Press A button to strart new game";
			}
			else
			{
				resetText = "Press R key to strart new game";
			}

			int gameOverWidth = MeasureText(gameOverText, 60);
			int resetWidth = MeasureText(resetText, 20);
			DrawText(gameOverText, window.width / 2 - gameOverWidth / 2, window.height / 2 - 30, 60, RED);
			DrawText(resetText, window.width / 2 - resetWidth / 2, window.height / 2 + 30, 20, RED);
		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
