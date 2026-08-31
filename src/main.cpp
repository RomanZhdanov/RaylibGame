#include "raylib.h"
#include "Player.h"
#include "GameResources.h"
#include "EnemyManager.h"
#include "WindowDimensions.h"
#include "Version.h"

int main()
{
	ChangeDirectory(GetApplicationDirectory());

	WindowDimensions window{ 1200, 800 };

	InitWindow(window.width, window.height, "Killer Fox");

	LoadTextures();

    InputSource input;
	Player knight;
	knight.setWindow(window);
	knight.setInput(&input);

	int const ENEMIES_LIMIT = 10;

	float spawnTime{ 2.f };
	float currentSpawnTime{};
	Vector2 spawnPositions[4] {
	    { window.width / 2.f, 0.f }, // top
		{ window.width / 2.f, static_cast<float>(window.height) }, // bottom
		{ 0.f, window.height / 2.f }, // left
		{ static_cast<float>(window.width), window.height / 2.f } // right
	};

	Color hudColor = LIME;
	EnemyManager enemiesManager;

	enemiesManager.setLimit(ENEMIES_LIMIT);

	while (!WindowShouldClose())
	{
		float delta = GetFrameTime();
		input.update();

		if (knight.isAlive())
		{
			currentSpawnTime -= delta;

			if (currentSpawnTime <= 0 && !enemiesManager.isFull())
			{
				currentSpawnTime = spawnTime;
				enemiesManager.create("goblin", spawnPositions[GetRandomValue(0, 3)], &knight, window);
				enemiesManager.create("slime", spawnPositions[GetRandomValue(0, 3)], &knight, window);
			}

			knight.update(delta);
			enemiesManager.update(delta);
		}
		else
		{
			bool reset = false;

			if (input.gamepadIsActive())
			{
				if (IsGamepadButtonPressed(input.getGamepad(), GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
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
				enemiesManager.deleteAll();
			}
		}

		BeginDrawing();

		ClearBackground(LIGHTGRAY);

		DrawText(TextFormat("Lives: %i", knight.getLives()), 10, 10, 20, hudColor);
		DrawText(TextFormat("Score: %i", knight.getScore()), window.width - 200, 10, 20, hudColor);
		DrawText(TextFormat("v%s", GAME_VERSION), 10, window.height - 20, 10, hudColor);

		knight.showHitboxRec(true);
		knight.showCollisionRec(true);
		knight.showHurtboxRec(true);
		enemiesManager.showCollisionRec(true);

		knight.draw();
		enemiesManager.draw();

		if (!knight.isAlive())
		{
			const char* gameOverText = "Game Over";
			const char* resetText{};

			if (input.gamepadIsActive())
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
