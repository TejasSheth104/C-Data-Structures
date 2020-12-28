#include<stdio.h>
#include<graphics.h>
#define width getmaxx()
#define height getmaxy()
#define gh height*0.75
int l=0;		//legs
void DrawManAndUmbrella(int x,int l){
//head
	circle(x,gh-45,10);
	line(x,gh-80,x,gh-30);
//hand
	line(x,gh-70,x+10,gh-60);
	line(x,gh-65,x+10,gh-55);
	line(x+10,gh-60,x+20,gh-70);
	line(x+10,gh-55,x+20,gh-70);
//legs
	line(x,gh-30,x+l,gh);
	line(x,gh-30,x-l,gh);
//umbrella
	pieslice(x+20,gh-120,0,180,40);
	line(x+20,gh-120,x+20,gh-70);
}
//void Rain(int x){
//	int i,rx,ry;
//	for(i=0;i<400;i++){
//		rx=rand() % width;		// random x coordinate
//		ry=rand() % height;		// random y coordinate
//		if(ry<gh-4){
//			if(ry<gh-120 || (ry>gh-120 && (rx<x-20 || rx>x+60)))
//				line(rx,ry,rx+0.5,ry+4);
//		}
//	}
//}
void main(){
	int gd=DETECT,gm,x=0;
	initgraph(&gd,&gm,"C:\\turboc3\\BGI");
//run until a key has been pressed.
	while(!kbhit()){
//Draw Ground
		line(0,gh,width,gh); 	// void line(int x1, int y1, int x2, int y2)
//		Rain(x);
		l=(l+2)%20;
		DrawManAndUmbrella(x,l);
		delay(50);
		cleardevice();
		x=(x+2)%width;
	}
	getch();
}
