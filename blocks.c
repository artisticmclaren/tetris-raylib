#include "include/raylib.h"

void drawl(int cposx,int cposy) { 
	DrawRectangle(cposx,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx+60,cposy,30,30,DARKGRAY);
}

void drawJ(int cposx,int cposy) {
	DrawRectangle(cposx,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy-30,30,30,DARKGRAY);
}

void drawL(int cposx,int cposy) {
	DrawRectangle(cposx,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy-30,30,30,DARKGRAY);
}

void drawO(int cposx,int cposy) {
	DrawRectangle(cposx,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx,cposy-30,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy-30,30,30,DARKGRAY);
}

void drawT(int cposx,int cposy) {
	DrawRectangle(cposx,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx,cposy-30,30,30,DARKGRAY);
}

void drawS(int cposx,int cposy) {
	DrawRectangle(cposx,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx,cposy-30,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy-30,30,30,DARKGRAY);
}

void drawZ(int cposx,int cposy) {
	DrawRectangle(cposx,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx+30,cposy,30,30,DARKGRAY);
	DrawRectangle(cposx,cposy-30,30,30,DARKGRAY);
	DrawRectangle(cposx-30,cposy-30,30,30,DARKGRAY);
}
