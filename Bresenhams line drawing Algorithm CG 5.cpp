#include <iostream>
#include <graphics.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    int x1, y1, x2, y2;

    
    cout << "Enter the coordinates of the first point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second point (x2 y2): ";
    cin >> x2 >> y2;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int slope_error=2*dy-dx;
    int x = x1;
    int y = y1;
    while(x<=x2){
      putpixel(x,y,WHITE);
      delay(50);
      x++;
      if(slope_error>=0){
         y++;
         slope_error-=2*dx;
      }else{
         slope_error+=2*dy;
      }
    }
     

    
    closegraph();

    return 0;
}
