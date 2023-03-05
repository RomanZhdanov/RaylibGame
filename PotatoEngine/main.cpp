#include "raylib.h"

int main()
{
	int windowWidth{ 800 };
	int windowHeight{ 600 };

	InitWindow(windowWidth, windowHeight, "Potato");
	
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}