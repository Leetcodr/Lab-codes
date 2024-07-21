
/*a) Write C++ program to draw the following pattern. Use DDA line and Bresenham‘s circle
drawing algorithm. Apply the concept of encapsulation.
OR
b) Write C++ program to draw the following pattern. Use DDA line and Bresenham‘s circle
drawing algorithm. Apply the concept of encapsulation.
*/
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void DDA_line(int x1, int y1, int x2, int y2, int icolour) {
    int i;
    float dx, dy, steps, Xinc, Yinc, X, Y;
    dx = (x2 - x1);
    dy = (y2 - y1);
    if (fabs(dx) > fabs(dy)) {
        steps = fabs(dx);
    } else {
        steps = fabs(dy);
    }
    Xinc = dx / steps;
    Yinc = dy / steps;

    X = x1;
    Y = y1;
    for (i = 0; i < steps; i++) {
        putpixel(floor(X), floor(Y), icolour);
        X = X + Xinc;
        Y = Y + Yinc;
    }
}

class bricircle {
public:
    void drawCircle(int x, int y, int r);

private:
    void mh(int &xi, int &del);
    void mv(int &yi, int &del);
    void mb(int &xi, int &yi, int &del);
};

void bricircle::drawCircle(int xc, int yc, int r) {
    int xi = 0, yi = r;
    int del = 3 - 2 * r;

    while (yi >= xi) {
        putpixel(xc + xi, yc + yi, RED);
        putpixel(xc - xi, yc + yi, RED);
        putpixel(xc + xi, yc - yi, RED);
        putpixel(xc - xi, yc - yi, RED);
        putpixel(xc + yi, yc + xi, RED);
        putpixel(xc - yi, yc + xi, RED);
        putpixel(xc + yi, yc - xi, RED);
        putpixel(xc - yi, yc - xi, RED);

        if (del < 0) {
            mh(xi, del);
        } else if (del > 0) {
            if (xi >= yi) {
                break;
            }
            mb(xi, yi, del);
        } else {
            mb(xi, yi, del);
        }
    }
}

void bricircle::mh(int &xi, int &del) {
    xi++;
    del = del + 4 * xi + 6;
}

void bricircle::mv(int &yi, int &del) {
    yi--;
    del = del - 4 * yi + 6;
}

void bricircle::mb(int &xi, int &yi, int &del) {
    xi++;
    yi--;
    del = del + 4 * (xi - yi) + 10;
}

void program_A() {
    DDA_line(60, 140, 60, 260, YELLOW);
    delay(200);
    DDA_line(60, 260, 340, 260, BLUE);
    delay(200);
    DDA_line(340, 260, 340, 140, YELLOW);
    delay(200);
    DDA_line(340, 140, 60, 140, BLUE);
    delay(200);

    DDA_line(200, 140, 60, 200, RED);
    delay(200);
    DDA_line(60, 200, 200, 260, GREEN);
    delay(200);
    DDA_line(200, 260, 340, 200, RED);
    delay(200);
    DDA_line(340, 200, 200, 140, GREEN);
    delay(200);

    bricircle is;
    setcolor(MAGENTA);
    is.drawCircle(200, 200, 55);
    delay(5000);
}

void program_B() {
    bricircle is;
    setcolor(BLUE);
    is.drawCircle(200, 200, 140);
    delay(200);

    DDA_line(200, 60, 320, 270, RED);
    delay(200);
    DDA_line(200, 60, 80, 270, GREEN);
    delay(200);
    DDA_line(320, 270, 80, 270, WHITE);
    delay(200);

    setcolor(CYAN);
    is.drawCircle(200, 200, 70);
    delay(5000);
}

int main() {
    int Choice;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    cout << "program A: 1" << endl;
    cout << "program B: 2" << endl;
    cout << "exit: 3" << endl;
    cout << "enter your choice: ";
    cin >> Choice;

    switch (Choice) {
    case 1:
        program_A();
        break;
    case 2:
        program_B();
        break;
    case 3:
        cout << "exit the program";
        exit(0);
    default:
        cout << "wrong choice";
        exit(0);
    }

    closegraph();
    return 0;
}
