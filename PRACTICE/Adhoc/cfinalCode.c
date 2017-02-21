#include<graphics.h>
#include<stdio.h>

#define WHITE 1
void draw8Points(int xc,int yc,int x ,int y){

                putpixel(xc + x, yc + y, WHITE);
                putpixel(xc - x, yc + y, WHITE);
                putpixel(xc + x, yc - y, WHITE);
                putpixel(xc - x, yc - y, WHITE);
                putpixel(xc + y, yc + x, WHITE);
                putpixel(xc - y, yc + x, WHITE);
                putpixel(xc + y, yc - x, WHITE);
                putpixel(xc - y, yc - x, WHITE);
                delay(100);

}

void midPointCircleDrawingAlgo(int xc,int yc,int radius){

 int  x, y, dp;


        dp = 1 - radius;
        x = 0, y = radius;

        do {
               draw8Points(xc,yc,x,y);
                x = x + 1;
                if (dp < 0) {
                        dp = dp + 2 * x + 1;
                } else {
                        y = y - 1;
                        dp = dp + 2 * (x - y) + 1;
                }

        } while (x < y);

}

void brehsenamLineDrawingAlgo_dx0(int x1,int y1,int x2,int y2){

	int dy,dx,y,x,p;
	dy = (y2 - y1);
	dx = (x2 - x1);

	p = 2 * (dx) - (dy);

	y = y1;
	x = x1;

	putpixel(x,y,WHITE);

	while(y <= y2){

		if(p < 0){

			y=y+1;
			x=x;
			p = p + 2 * (dx);
		}
		else{

			x=x+1;
			y=y+1;
			p = p + 2 * (dy - dx);
		}
		putpixel(x,y,WHITE);
	}
}

void brehsenamLineDrawingAlgo(int x1,int y1,int x2,int y2){


	int dx,dy,x,y,p;
	dx = (x2 - x1);
	dy = (y2 - y1);

    int xchange=(dx==0)?0:1;
    int ychange=(dy>=0)?( (dy==0) ? ychange=0 : 1 ):-1;
	p = 2 * (dy) - (dx);

	x = x1;
	y = y1;

	putpixel(x,y,WHITE);

	while(x < x2 || x == x2){

		if(p < 0){

			x=x+xchange;
			y=y;
			p = p + 2 * (dy);
		}
		else{

			x=x+xchange;
			y=y+ychange;
			p = p + 2 * (dy - dx);
		}
		putpixel(x,y,WHITE);
	}
}

void brehsenamLineDrawingAlgo_Ydec(int x1,int y1,int x2,int y2){

	int dx,dy,x,y,p;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);

	p = 2 * (dy) - (dx);

	x = x1;
	y = y1;

	putpixel(x,y,WHITE);

	while(x < x2 || x == x2){

		if(p < 0){

			x=x+1;
			y=y;
			p = p + 2 * (dy);
		}
		else{

			x=x+1;
			y=y-1;
			p = p + 2 * (dy - dx);
		}
		putpixel(x,y,WHITE);
	}
}

int main(){

    int gd,gm,i;

    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,NULL);

    //first
    midPointCircleDrawingAlgo(100,100,50);
    brehsenamLineDrawingAlgo(100,150,100,350);
    brehsenamLineDrawingAlgo(50,300,100,250);
    brehsenamLineDrawingAlgo(100,250,150,300);
    brehsenamLineDrawingAlgo(50,400,100,350);
    brehsenamLineDrawingAlgo(100,350,150,400);

     //middle
    midPointCircleDrawingAlgo(300,100,50);
    brehsenamLineDrawingAlgo(300,150,300,350);
    brehsenamLineDrawingAlgo(250,250,350,250);
    brehsenamLineDrawingAlgo(250,400,300,350);
    brehsenamLineDrawingAlgo(300,350,350,400);

    //last
    midPointCircleDrawingAlgo(500,100,50);
    brehsenamLineDrawingAlgo_dx0(500,150,500,350);
    brehsenamLineDrawingAlgo(450,200,500,250);
    brehsenamLineDrawingAlgo_Ydec(500,250,550,200);
    brehsenamLineDrawingAlgo_Ydec(450,400,500,350);
    brehsenamLineDrawingAlgo(500,350,550,400);

    getch();
    closegraph();
    return 0;
}
