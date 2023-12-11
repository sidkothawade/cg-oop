#include<iostream>
#include<graphics.h>
using namespace std;

void drawPolygon(int points[][2], int n) {
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        line(points[i][0], points[i][1], points[next][0], points[next][1]);
    }
}

void scanFill(int points[][2], int n, int fill_color) {
    int i, j, k;
    int x, y;
    for (y = 0; y < getmaxy(); y++) {
        for (x = 0; x < getmaxx(); x++) {
            int count = 0;
            for (i = 0, j = n - 1; i < n; j = i++) {
                if ((points[i][1] > y) != (points[j][1] > y) &&
                    (x <= (points[j][0] - points[i][0]) * (y - points[i][1]) / (points[j][1] - points[i][1]) + points[i][0]))
                    count++;
            }
            if (count % 2 == 1) {
                putpixel(x, y, fill_color);
            }
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int n;
    cout << "Enter the number of vertices of the concave polygon: ";
    cin >> n;

    int points[n][2];

    cout << "Enter the coordinates of the vertices:\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i + 1 << ": ";
        cin >> points[i][0] >> points[i][1];
    }

    int fill_color;
    cout << "Enter the fill color (integer value): ";
    cin >> fill_color;

    drawPolygon(points, n);
    scanFill(points, n, fill_color);

    getch();
    closegraph();
    return 0;
}
