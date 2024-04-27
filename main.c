#include "include/raylib.h"
#include "blocks.c"
#include <stdio.h>
#include <stdlib.h>


int main(void) { // this code is a mess but it works
	int width = 1280;
	int height = 720;
	int whalf = width/2;
	int hhalf = height/2;

	bool lkeyup = true;
	bool rkeyup = true;

	int levels[] = {120,110,100,95,85,75,60,50,40,30,20,15};
	int level=0;
	int gridsize[] = {10,20};
	int framespast = 0;
	int cblockpos[] = {whalf-30,60};

	InitWindow(width,height, "Tetris");
	SetTargetFPS(120);

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		{
			int tw = MeasureText("Tetris",20);
			DrawText("Tetris",whalf-tw/2,10,20,LIGHTGRAY);
		}
		DrawRectangle(whalf-150,60,30*gridsize[0],30*gridsize[1],LIGHTGRAY);
		if (framespast==levels[level]) {
			cblockpos[1]+=30;
			framespast=0;
		}

		// reset rkeyup and lkeyup so you can press the button again
		if (IsKeyUp(KEY_RIGHT)) rkeyup=true;
		if (IsKeyUp(KEY_LEFT)) lkeyup=true;

		// move current block
		if (IsKeyDown(KEY_RIGHT) && rkeyup==true) {
			cblockpos[0]+=30;
			rkeyup=false;
		}
		
		if (IsKeyDown(KEY_LEFT) && lkeyup==true) {
			cblockpos[0]-=30;
			lkeyup=false;
		}

		if (IsKeyDown(KEY_DOWN)) {
			if (framespast % 2 == 0) cblockpos[1]+=30; // drops block one gridspace every 2 frames
		}

		if (IsKeyDown(KEY_SPACE)) {
			// TODO: hard drop
		}

		drawO(cblockpos[0],cblockpos[1]);

		EndDrawing();
		framespast++;
	}

	CloseWindow();
	return 0;
}
