#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define MAX_VALUE 100

void fillArrayWithZeros(int array[], int size) {
    for(int i = 0; i < size; i++) {
        array[i] = 0;
        printf("i: %2d, value: %d\n", i, array[i]);
    }
}

void fillArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        array[i] = (i + 1);
        printf("i: %2d, value: %d\n", i, array[i]);
    }
}

void fillArrayRandom(int array[], int size) {
    for(int i = 0; i < size; i++) {
        array[i] = rand();
    }
}

int main() {
    int size;

    int c;
    printf("%s\n", "Zadejte velikost pole: ");
    if(scanf("%d", &size) != 1 || size > MAX_VALUE || size <= 0) {
        printf("%s\n", "Nespravny vstup.");
        return EXIT_FAILURE;
    }

    while((c = getchar()) != '\n' && c != EOF) {
        if(!isspace((unsigned char) c)) {
            printf("%s\n", "Nespravny vstup.");
            return EXIT_FAILURE;
        }
    }

    int array[size];
    fillArray(array, size);
    // fillArrayWithZeros(array, size);

    printf("sizeof(pole) = %ld\n", sizeof(array));
    printf("sizeof(pole[0]) = %ld\n", sizeof(array[0]));

    return EXIT_SUCCESS;
}