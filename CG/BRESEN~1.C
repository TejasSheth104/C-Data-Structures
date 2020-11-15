#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int main()
{
    int gdriver=DETECT, gmode, error, x0, y0, x1, y1;
    int dx, dy, p, x, y,k;
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
    printf("\n\tBresenham's Line Drawing Algorithm ->\n");
    printf("Enter co-ordinates of first point: ");
    scanf("%d%d", &x0, &y0);
    printf("Enter co-ordinates of second point: ");
    scanf("%d%d", &x1, &y1);
    dx=x1-x0;
    dy=y1-y0;
    x=x0;
    y=y0;
    p=2*dy-dx;
    for(k=0;k<dx;k++){
	delay(10);
	if(p>=0){
	    putpixel(x,y,7);
		    x=x+1;
	    y=y+1;
	    p=p+2*dy-2*dx;
	}
	else{
	    putpixel(x,y,7);
	    p=p+2*dy;
	    x=x+1;
	}
    }
    getch();
    return 0;
}

