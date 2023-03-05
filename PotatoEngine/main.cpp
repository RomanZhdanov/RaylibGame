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
		4.f
	};

	bush.setPosition(Vector2{});

	AnimatedSprite knight{
		LoadTexture("assets/knight_run_spritesheet.png"),
		5.f,
		6,
		1,
		0.1f,
		true
	};

	knight.setPosition(Vector2{});

	while (!WindowShouldClose())
	{
		knight.update(GetFrameTime());

		BeginDrawing();

		ClearBackground(WHITE);

		//bush.draw();
		knight.draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}