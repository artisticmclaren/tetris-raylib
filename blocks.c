#include "include/raylib.h"

int drawl(int cposx,int cposy) { 
	DrawRectangle(cposx,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx+60,cposy,30,30,DARKGRAY);
	return 0;
}

int drawJ(int cposx,int cposy) {
	DrawRectangle(cposx,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy-30,30,30,DARKGRAY);
	return 0;
}

int drawL(int cposx,int cposy) {
	DrawRectangle(cposx,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy-30,30,30,DARKGRAY);
	return 0;
}

int drawO(int cposx,int cposy) {
	DrawRectangle(cposx,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx,cposy-30,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy-30,30,30,DARKGRAY);
	return 0;
}

int drawT(int cposx,int cposy) {
	DrawRectangle(cposx,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx,cposy-30,30,30,DARKGRAY);
	return 0;
}

int drawS(int cposx,int cposy) {
	DrawRectangle(cposx,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx,cposy-30,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy-30,30,30,DARKGRAY);
	return 0;
}

int drawZ(int cposx,int cposy) {
	DrawRectangle(cposx,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx,cposy-30,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy-30,30,30,DARKGRAY);
	return 0;
}

int getBlockFromId(int id,int x, int y) {
	switch(id) {
		case 0:
			return drawl(x,y);
			break;
		case 1:
			return drawJ(x,y);
			break;
		case 2:
			return drawL(x,y);
			break;
		case 3:
			return drawO(x,y);
			break;
		case 4:
			return drawT(x,y);
			break;
		case 5:
			return drawS(x,y);
			break;
		case 6:
			return drawZ(x,y);
			break;
		default:
			return 1;
	}
}

int getFarLeftCollision(int id,int x) {
	if (id==3) {
		return x;
	}
	return x-30;
}

int getFarRightCollision(int id,int x) {
	if (id==0) {
		return x+30;
	}
	return x+30;
}
