#include "include/raylib.h"
#include "blocks.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randrange(int min, int max) {
	int output = (rand() % (max-min+1))+min;
	return output;
}

int main(void) { // this code is a mess but it works
	int width = 1280;
	int height = 720;
	int whalf = width/2;
	int hhalf = height/2;

	int permblocks[5000][3] = {{}}; 
	int pblockcount=0;

	bool lkeyup = true;
	bool rkeyup = true;
	bool hdup = true;

	int levels[] = {120,110,100,95,85,75,60,50,40,30,20,15};
	int level=0;
	int gridsize[] = {10,20};
	int framespast = 0;
	int cblockpos[] = {whalf-30,60};
	
	srand(time(0));
	int cblockid = randrange(0,6);

	InitWindow(width,height, "Tetris");
	SetTargetFPS(120);

	{
		int i = 0;
		for (i=0;i<5000;i++) {
			permblocks[i][0]=-1;
			permblocks[i][1]=-1;
			permblocks[i][2]=-1;
		}
	}

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		{
			int tw = MeasureText("Tetris",20);
			DrawText("Tetris",whalf-tw/2,10,20,LIGHTGRAY);
		}
		DrawRectangle(whalf-150,60,30*gridsize[0],30*gridsize[1],LIGHTGRAY);
		if (framespast==levels[level]) {
			if (cblockpos[1]!=630) {
				cblockpos[1]+=30;
			}
			framespast=0;
		}

		{ // draw all perm blocks with this really strange looking block of code
			int i=0;
			for (i=0;i<500;i++) {
				if (permblocks[i][0]!=-1) {
					switch(permblocks[i][2]) {
						case 0:
							drawl(permblocks[i][0],permblocks[i][1]);
							break;
						case 1:
							drawJ(permblocks[i][0],permblocks[i][1]);
							break;
						case 2:
							drawL(permblocks[i][0],permblocks[i][1]);
							break;
						case 3:
							drawO(permblocks[i][0],permblocks[i][1]);
							break;
						case 4:
							drawT(permblocks[i][0],permblocks[i][1]);
							break;
						case 5:
							drawS(permblocks[i][0],permblocks[i][1]);
							break;
						case 6:
							drawZ(permblocks[i][0],permblocks[i][1]);
							break;
						default:
							// hopefully wont be called
					}
				}
			}
		}
							

		// reset rkeyup and lkeyup so you can press the button again
		if (IsKeyUp(KEY_RIGHT)) rkeyup=true;
		if (IsKeyUp(KEY_LEFT)) lkeyup=true;

		// move current block
		if (IsKeyDown(KEY_RIGHT) && rkeyup==true) {
			if (cblockpos[0]!=whalf+90) {
				cblockpos[0]+=30;
				rkeyup=false;
			}
		}
		
		if (IsKeyDown(KEY_LEFT) && lkeyup==true) {
			if (cblockpos[0]!=whalf-150) {
				cblockpos[0]-=30;
				lkeyup=false;
			}
		}

		if (IsKeyDown(KEY_DOWN)) {
			if (framespast % 2 == 0 && cblockpos[1]!=630) cblockpos[1]+=30; // drops block one gridspace every 2 frames
		}

		if (IsKeyUp(KEY_SPACE)) {
			hdup=true;
		}
		if (IsKeyDown(KEY_SPACE) && hdup==true) {
			cblockpos[1]=630;
			hdup=false;
		}

		if (cblockpos[1]==630) {
			permblocks[pblockcount][0]=cblockpos[0];
			permblocks[pblockcount][1]=cblockpos[1];
			permblocks[pblockcount][2]=cblockid;
			pblockcount++;

			srand(time(0));
			cblockid=randrange(0,6);
			cblockpos[0]=whalf-30;
			cblockpos[1]=60;
		}

		getBlockFromId(cblockid,cblockpos[0],cblockpos[1]);

		DrawText(TextFormat("block id:%d",cblockid),0,50,20,LIGHTGRAY);
		DrawText(TextFormat("placed: %d",pblockcount),0,75,20,LIGHTGRAY);
		EndDrawing();
		framespast++;
	}

	CloseWindow();
	return 0;
}
