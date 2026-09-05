#include <array>
#include "raylib.h"
#include "Player.h"
#include "GameResources.h"
#include "EnemyManager.h"
#include "WindowDimensions.h"
#include "Version.h"
#include "ShuffleBag.h"

static float GetRandomSpawnTime(float min, float max)
{
    return GetRandomValue(static_cast<int>(min * 1000), static_cast<int>(max * 1000)) / 1000.f;
}

int main()
{
	ChangeDirectory(GetApplicationDirectory());

	WindowDimensions window{ 1200, 800 };

	InitWindow(window.width, window.height, "Killer Fox");

	LoadTextures();

	std::mt19937 rng(std::random_device{}());

    InputSource input;
	Player knight;
	ShuffleBag enemiesBag;

	knight.setWindow(window);
	knight.setInput(&input);

	float const ENEMIES_SPAWN_TIME_MAX = 2.f ;
	float const ENEMIES_SPAWN_TIME_MIN = 0.5 ;
	int const ENEMIES_INITIAL_LIMIT = 1;
	float const ENEMIES_LIMIT_INTERVAL = 10.f;

	float currentSpawnTime = ENEMIES_SPAWN_TIME_MAX;
	float currentEnemiesLimitTime = ENEMIES_LIMIT_INTERVAL;
	std::array<Vector2, 4> spawnPositions {{
	    { window.width / 2.f, 0.f }, // top
		{ window.width / 2.f, static_cast<float>(window.height) }, // bottom
		{ 0.f, window.height / 2.f }, // left
		{ static_cast<float>(window.width), window.height / 2.f } // right
	}};
	enemiesBag.Add("goblin", 10);
	enemiesBag.Add("goblin-boss", 1);
	enemiesBag.Add("slime", 20);
	enemiesBag.Shuffle(rng);

	Color hudColor = LIME;
	EnemyManager enemiesManager;

	enemiesManager.setLimit(ENEMIES_INITIAL_LIMIT);

	while (!WindowShouldClose())
	{
		float delta = GetFrameTime();
		input.update();

		if (knight.isAlive())
		{
			currentSpawnTime -= delta;
			currentEnemiesLimitTime -= delta;

			if (currentSpawnTime <= 0 && !enemiesManager.isFull())
			{
				currentSpawnTime = GetRandomSpawnTime(ENEMIES_SPAWN_TIME_MIN, ENEMIES_SPAWN_TIME_MAX);
				std::string enemyType = enemiesBag.GetNext(rng);
			    Vector2 enemyPosition = spawnPositions[GetRandomValue(0, static_cast<int>(spawnPositions.size()) -1)];
				enemiesManager.create(enemyType, enemyPosition, &knight, window);
			}

			if (currentEnemiesLimitTime <= 0)
			{
			    currentEnemiesLimitTime = ENEMIES_LIMIT_INTERVAL;
				int curLimit = enemiesManager.getLimit();
				enemiesManager.setLimit(curLimit + 1);
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
				enemiesManager.setLimit(ENEMIES_INITIAL_LIMIT);
				currentSpawnTime = ENEMIES_SPAWN_TIME_MAX;
				currentEnemiesLimitTime = ENEMIES_LIMIT_INTERVAL;
			}
		}

		BeginDrawing();

		ClearBackground(LIGHTGRAY);

		DrawText(TextFormat("HP: %i", knight.getHealth()), 10, 10, 20, hudColor);
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
