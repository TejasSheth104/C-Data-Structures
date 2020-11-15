#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main(){
	int gdriver=DETECT, gmode, xc,yc,r,p,x,y;
	initgraph(&gdriver,&gmode,"c:\\turboc3\\bgi");
	printf("\n\tMidPoint Circle Drawing Algorithm ->\n");
	printf("Enter the Co-ordinates of Center");
	scanf("%d%d",&xc,&yc);
	printf("Enter Radius");
	scanf("%d",&r);
	p=1-r;
	x=0;
	y=r;
	while(x<=y){
		putpixel(xc+x,yc+y,RED);
		putpixel(xc+y,yc+x,RED);
		putpixel(xc-x,yc+y,RED);
		putpixel(xc+y,yc-x,RED);
		putpixel(xc-x,yc-y,RED);
		putpixel(xc-y,yc-x,RED);
		putpixel(xc+x,yc-y,RED);
		putpixel(xc-y,yc+x,RED);
		if(p<0){
			x=x+1;
			p=p+2*x+1;
		}
		else{
			x=x+1;
			y=y-1;
			p=p+2*x+1-2*y;
		}
	}
	getch();
}

