#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Triangle {
    int a;
    int b;
    int c;
} triangle;

int isTriangleRightAngled(triangle t) {
    if((pow(t.a, 2) + pow(t.b, 2) == pow(t.c, 2)) || (pow(t.b, 2) + pow(t.c, 2) == pow(t.a, 2)) || (pow(t.a, 2) + pow(t.c, 2) == pow(t.b, 2))) {
        // printf("a: %d b: %d c: %d\n", t.a, t.b, t.c);
        return 1;
    }
    return 0;
}

int isTriangleIsosceled(triangle t) {
    if((t.a == t.b) || (t.b == t.c) || (t.a == t.c)) {
        return 1;
    }
    return 0;
}

int isTriangleEquilateral(triangle t) {
    if((t.a == t.b) && (t.a == t.c) && (t.b == t.c)) {
        return 1;
    }
    return 0;
}


int main() {
    triangle t;
    printf("%s\n", "Zadejte rozměry trojúhelníku: ");

    if(scanf("%d %d %d", &t.a, &t.b, &t.c) != 3 || (t.a <= 0 || t.b <= 0 || t.c <= 0)) {
        printf("%s\n", "Nespravny vstup!");
        return EXIT_FAILURE;
    }

    printf("Trojúhelník: (a: %d, b: %d, c: %d)\n", t.a, t.b, t.c);
    printf("%s\n", "-------------------------------");
    isTriangleRightAngled(t) ? printf("%s\n", "Trojúhelník JE pravoúhlý") : printf("%s\n", "Trojúhelník NENÍ pravoúhlý");
    isTriangleIsosceled(t) ? printf("%s\n", "Trojúhelník JE rovnoramenný") : printf("%s\n", "Trojúhelník NENÍ rovnoramenný");
    isTriangleEquilateral(t) ? printf("%s\n", "Trojúhelník JE rovnostranný") : printf("%s\n", "Trojúhelník NENÍ rovnostranný");
    printf("%s\n", "-------------------------------");

    return EXIT_SUCCESS;
}