#include "include/raylib.h"
#include "blocks.c"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int width = 1280;
	int height = 720;
	int whalf = width/2;
	int hhalf = height/2;

	InitWindow(width,height, "Tetris");
	SetTargetFPS(120);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		{
			int tw = MeasureText("Tetris",20);
			DrawText("Tetris",whalf-tw/2,10,20,LIGHTGRAY);
		}
		DrawRectangle(whalf-150,60,300,600,LIGHTGRAY);
		drawl(200,50);
		drawJ(200,150);
		drawL(200,250);
		drawO(200,350);
		drawT(200,450);
		drawS(200,550);
		drawZ(200,650);

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
