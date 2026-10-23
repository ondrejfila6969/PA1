#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
} point;

point getRandomPoint() {
    point p;
    p.x = 4;
    p.y = p.x * 4;
    return p;
}

void printPoint(point p) {
    printf("Point: (x: %d, y: %d)\n", p.x, p.y);
}

int main() {
    point randomPoint = getRandomPoint();
    printPoint(randomPoint);
    return EXIT_SUCCESS;
}