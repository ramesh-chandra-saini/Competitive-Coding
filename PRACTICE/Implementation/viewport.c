/*
Reference

http://www.sourcecodesolutions.in/2010/09/implementation-of-window-viewport.html
http://2k8618.blogspot.in/2011/11/window-to-viewport-transformation-c.html
http://3rdyearcselabprograms.blogspot.in/2010/02/window-to-viewport-mapping.html
*/

#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
int x=-50;
int xvmin,xvmax,yvmin,yvmax;
void port(int x1,y1,x2,y2){

    float sx=((xvmax-xvmin)/(xwmax-xwmin));
    float sy=((yvmax-yvmin)/(ywmax-xwmin));

    x1=xvmin+((x1-xwmin)*sx);
    y1=yvmin+((y1-ywmin)*sy);
    
    x2=xvmin+((x2-xwmin)*sx);
    y2=yvmin+((y2-ywmin)*sy);
    
    line(x1,y1,x2,y2);
}
void drawHomePort(){
	//upper triangle
	port(200,200,500,200);
	port(200,200,350,100);
	port(500,200,350,100);
	
	//lower outer boundry
	port(250,200,250,400);
	port(250,400,450,400);
	port(450,400,450,200);
	
	//door 
	port(300,400,300,300);
	port(400,400,400,300);
	port(300,300,400,300);
	
	//window
	port(260,220,290,220);
	port(260,220,260,260);
	port(290,220,290,260);
	port(260,260,290,260);
	//port(250,250,300,250);
	//port(300,250,300,200);
}
void drawHomeWindow(){
	//upper triangle
	line(200,200,500,200);
	line(200,200,350,100);
	line(500,200,350,100);
	
	//lower outer boundry
	line(250,200,250,400);
	line(250,400,450,400);
	line(450,400,450,200);
	
	//door 
	line(300,400,300,300);
	line(400,400,400,300);
	line(300,300,400,300);
	
	//window
	line(260,220,290,220);
	line(260,220,260,260);
	line(290,220,290,260);
	line(260,260,290,260);
	//line(250,250,300,250);
	//line(300,250,300,200);
}
int main(){

	int gd,gm,i;

	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	cleardevice();
  	outtextxy(250,80,"window port");
    	rectangle(200-10,100-10,500+10,400+10);
	drawHomeWindow();
	delay(5000);
	cleardevice();

  	outtextxy(250,80,"view port");
    	rectangle(200-10,100-10,500+10,400+10);
	drawHomePort();
	delay(10000);
	closegraph();
	return 0;
}
