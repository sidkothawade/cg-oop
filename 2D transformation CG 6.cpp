#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

void drawrectangle(int x1,int y1,int x2,int y2){
	rectangle(x1,y1,x2,y2);
}


int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	int x1,y1,x2,y2;
	char ch;
	cout<<"enter x1,y1,x2,y2";
	cin>>x1>>y1>>x2>>y2;
	drawrectangle(x1,y1,x2,y2);
	cout<<"\n Type : \n 1 for translation \n 2 for scaling \n 3 for roatation";
	cin>>ch;
	switch(ch){
		case '1':
			int tx, ty;
			cout<<"enter translating factors tx and ty";
			cin>>tx>>ty;
			
			drawrectangle(x1,y1,x2+tx,y2+ty);
			break;
		case '2':
			float sx,sy;
			cout<<"enter scaling factor sx and sy";
			cin>>sx>>sy;
			
			drawrectangle(x1,y1,x2*sx,y2*sy);
			break;

		case '3':
			float angle;
			cout<<"enter angle in degrees";
			cin>>angle;
			float radian=angle*3.14159/180.0;
			drawrectangle(x1,y1,(x2*cos(radian)-y2*sin(radian)),(x2*sin(radian)-y2*cos(radian)));
			break;
	} 

	
	getch();
	closegraph();

}