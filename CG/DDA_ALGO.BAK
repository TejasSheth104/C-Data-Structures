#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void main(){
	int x1,x2,y1,y2,step,i,dx,dy;
	float x,y,xinc,yinc;
	int gd=DETECT, gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	printf("\n\tDigital Differential Analyser Algorithm ->\n");
	printf("Enter the Starting Co-ordinates - ");
	scanf("%d%d", &x1,&y1);
	printf("Enter the Ending Co-ordinates - ");
	scanf("%d%d", &x2,&y2);
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>abs(dy))
		step=abs(dx);
	else
		step=abs(dy);
	xinc=dx/(float)step;
	yinc=dy/(float)step;
	x=x1;
	y=y1;
	putpixel(x,y,10);
	for(i=0;i<step;i++){
		putpixel(x,y,10);
		x=x+xinc;
		y=y+yinc;
		delay(10);
	}
	getch();
	closegraph();
}