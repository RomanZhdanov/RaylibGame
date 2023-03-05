#include "raylib.h"
#include "Sprite.h"
#include "AnimatedSprite.h"

int main()
{
	int windowWidth{ 800 };
	int windowHeight{ 600 };

	InitWindow(windowWidth, windowHeight, "Potato");
	
	Sprite bush{
		LoadTexture("assets/bush.png"),
		1.f
	};

	bush.setPosition(Vector2{});

	AnimatedSprite knightRun{
		LoadTexture("assets/knight_run_spritesheet.png"),
		6.f,
		6,
		1,
		1.f / 12.f,
		true
	};

	AnimatedSprite knightIdle{
		LoadTexture("assets/knight_idle_spritesheet.png"),
		6.f,
		6,
		1,
		1.f / 12.f,
		true
	};

	AnimatedSprite* animations[]{
		&knightIdle,
		&knightRun
	};

	while (!WindowShouldClose())
	{
		AnimatedSprite* animation = animations[0];

		if (IsKeyDown(KEY_SPACE))
		{
			animation = animations[1];
		}

		animation->update(GetFrameTime());

		BeginDrawing();

		ClearBackground(WHITE);

		bush.draw();
		animation->draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}