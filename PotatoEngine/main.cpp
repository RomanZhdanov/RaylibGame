#include "raylib.h"
#include "AnimatedSprite.h"
#include "Player.h"
#include "GameResources.h"
#include "EnemyFactory.h"

int main()
{
	int windowWidth{ 800 };
	int windowHeight{ 600 };

	InitWindow(windowWidth, windowHeight, "Potato");
	
	LoadTextures();

	EnemyFactory enemyFactory;

	Enemy* goblin = enemyFactory.CreateEnemy("goblin");

	AnimatedSprite bush{
		textureManager.get("bush"),
		1.f, 1, 1, 0.f, true
	};

	Vector2 goblinPos{ 300.f, 500.f };
	bush.setPosition(goblinPos);
	goblin->setPosition(goblinPos);

	Player knight;

	while (!WindowShouldClose())
	{
		float delta = GetFrameTime();
		bush.update(delta);
		knight.update(delta);
		goblin->update(delta);

		BeginDrawing();

		ClearBackground(WHITE);

		bush.draw();
		knight.draw();
		goblin->draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}