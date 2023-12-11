#include <iostream>
#include <graphics.h>
using namespace std;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Define the rectangular clipping window
const int xMin = 50, yMin = 50, xMax = 100, yMax = 100;

int computeCode(double x, double y) {
    int code = INSIDE;

    if (x < xMin) {
        code |= LEFT;
    } else if (x > xMax) {
        code |= RIGHT;
    }

    if (y < yMin) {
        code |= BOTTOM;
    } else if (y > yMax) {
        code |= TOP;
    }

    return code;
}


void drawwindow(int xmin,int ymin,int xmax,int ymax)
{
	line(xmin,ymin,xmin,ymax);
	line(xmin,ymax,xmax,ymax);
	line(xmax,ymax,xmax,ymin);
	line(xmax,ymin,xmin,ymin);
}

void drawline(double x1,double y1,double x2,double y2)
{
	line(x1,y1,x2,y2);
}

void cohenSutherland(double x1, double y1, double x2, double y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if (!(code1 | code2)) { // Both endpoints are inside the clipping window
            accept = true;
            break;
        } else if (code1 & code2) { // Both endpoints are outside the same region
            break;
        } else {
            int codeOut = code1 ? code1 : code2;

            double x, y;
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        cout << "Line segment after clipping: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")\n";
        	drawwindow(xMin,yMin,xMax,yMax);
        	drawline(x1,y1,x2,y2);
    } else {
        cout << "Line segment is completely outside the clipping window.\n";
    }
}

int main() {
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	
    double x1, y1, x2, y2;
	drawwindow(xMin,yMin,xMax,yMax);
    cout << "Enter the coordinates of the line segment (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    cout << "Line segment before clipping: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")\n";
	drawline(x1,y1,x2,y2);
	
	delay(2000);
	cleardevice();
    cohenSutherland(x1, y1, x2, y2);
    getch();
closegraph();
    return 0;
}

