#include<stdio.h>
#include<graphics.h>
#define width getmaxx()
#define height getmaxy()
#define gh height*0.90

int l=0;
void DrawManAndUmbrella(int x,int l){
//head
    circle(x,gh-90,10);
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
    setfillstyle(SOLID_FILL,BLUE);
	pieslice(x+20,gh-120,0,180,40);
    line(x+20,gh-120,x+20,gh-70);
}
void Sun(int x,int y){
    int i,rx,ry;
    rx=width%x+500;
    ry=height%y+75;
    setfillstyle(SOLID_FILL,YELLOW);
	pieslice(rx,ry,0,360,30);
}
void main(){
    int gd=DETECT,gm,x=0,x_sun=10,y_sun=10;
    initgraph(&gd,&gm,"C:\\turboc3\\BGI");
    while(!kbhit()){
//Draw Ground
		setbkcolor(CYAN);
		line(0,gh,width,gh);
		Sun(x_sun,y_sun);
		l=(l+2)%20;			// legs
		DrawManAndUmbrella(x,l);
		DrawManAndUmbrella(x+500,l);
		delay(50);
		cleardevice();
		x=(x+2)%width;
	}
    getch();
}
