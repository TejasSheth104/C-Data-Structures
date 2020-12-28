#include<stdio.h>
#include<graphics.h>
#define width getmaxx()
#define height getmaxy()
#define gh height*0.75
int l=0;
void DrawManAndUmbrella(int x,int l)
{
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
pieslice(x+20,gh-120,0,180,40);
line(x+20,gh-120,x+20,gh-70);
}
void Rain(int x)
{
int i,rx,ry;
for(i=0;i<400;i++)
{
 rx=rand() % width;
 ry=rand() % height;
 if(ry<gh-4)
 {
 if(ry<gh-120 || (ry>gh-120 && (rx<x-20 || rx>x+60)))
 line(rx,ry,rx+0.5,ry+4);
 }
}
}
void main()
{
 int gd=DETECT,gm,x=0;

 initgraph(&gd,&gm,"C:\\turboc3\\BGI");
 while(!kbhit())
 {
 //Draw Ground
 line(0,gh,width,gh);
 Rain(x);
 l=(l+2)%20;
 DrawManAndUmbrella(x,l);
 delay(75);
 cleardevice();
 x=(x-2)%width;
}
 getch();
}
