#include <iostream>
#include <graphics.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    float x1, y1, x2, y2;

    
    cout << "Enter the coordinates of the first point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second point (x2 y2): ";
    cin >> x2 >> y2;

    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps = max(abs(dx),abs(dy));

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = x1;
    float y = y1;

 
    for (int i = 1; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
        
    }

    delay(5000);
    closegraph();

    return 0;
}
