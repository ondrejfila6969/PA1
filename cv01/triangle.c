#include <stdio.h>
#include <stdlib.h>

int main() {
    int height;
    printf("%s\n", "Zadejte výšku trojúhelníku: ");

    if(scanf("%d", &height) != 1) {
        printf("%s\n", "Neplatný vstup!");
        return EXIT_FAILURE;
    }

    for(int row = 1; row <= height; row++) {
        for(int star = 1; star <= row; star++) {
            printf("%s", "*");
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}