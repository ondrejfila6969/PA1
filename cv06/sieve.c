#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_VALUE 500
int main() {
    int size;

    int c;
    printf("%s\n", "Zadej rozměr: ");
    if(scanf("%d", &size) != 1 || size <= 0 || size > MAX_VALUE) {
        printf("%s\n", "Nespravny vstup.");
        return EXIT_FAILURE;
    }

    while((c = getchar()) != '\n' && c != EOF) {
        if(!isspace((unsigned char) c)) {
            printf("%s\n", "Nespravny vstup.");
            return EXIT_FAILURE;
        }
    }

    bool array[size];

    

    return EXIT_SUCCESS;
}