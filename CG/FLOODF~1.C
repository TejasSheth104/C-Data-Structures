#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void flood(int x, int y, int new_col, int old_col) {
	if (getpixel(x, y) == old_col) {
		putpixel(x, y, new_col);
		flood(x + 1, y, new_col, old_col);
		flood(x - 1, y, new_col, old_col);
		flood(x, y + 1, new_col, old_col);
		flood(x, y - 1, new_col, old_col);
	}
}

void main(){
	int gd=DETECT, gm;
	int top=50, left=50, bottom=300, right=300;
	int x=51, y=51, newcolor=12, oldcolor=0;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	rectangle(left, top, right, bottom);
	flood(x,y,newcolor,oldcolor);
	getch();
	closegraph();
}

