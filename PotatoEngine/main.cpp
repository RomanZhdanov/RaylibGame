#include "raylib.h"
#include "Sprite.h"

int main()
{
	int windowWidth{ 800 };
	int windowHeight{ 600 };

	InitWindow(windowWidth, windowHeight, "Potato");
	
	Sprite bush{
		LoadTexture("assets/bush.png"),
		Vector2{},
		4.f
	};

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		bush.draw();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}