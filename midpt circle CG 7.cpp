#include<iostream>
#include<graphics.h>
using namespace std;

void drawcircle(int xc,int yc,int radius){
	int x=radius , y=0;
	int error=1-x;
	while (x>=y){
		putpixel(xc+x,yc+y,WHITE);
		putpixel(xc+x,yc-y,WHITE);
		putpixel(xc-x,yc+y,WHITE);
		putpixel(xc-x,yc-y,WHITE);
		putpixel(xc+y,yc+x,WHITE);
		putpixel(xc+y,yc-x,WHITE);
		putpixel(xc-y,yc+x,WHITE);
		putpixel(xc-y,yc-x,WHITE);
		y++;
		if(error<0){
			error+=2*y+1;
			
		}else{
			x--;
			error+=2*(y-x)+1;
		}
		
	}
}
int main(){
	int gd=DETECT , gm;
	initgraph(&gd,&gm,"");
	int xc=300,yc=300,radius=100;
	drawcircle(xc,yc,radius);
	delay(5000);
	closegraph();
	return 0;
	
}
