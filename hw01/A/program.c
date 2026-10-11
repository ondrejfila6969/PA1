#include <stdio.h>
#include <stdlib.h>


int validateInputFormat(int result, int end) {
    if(result != 3 || end == -1) {
        printf("%s\n", "Nespravny vstup.");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int validateRGBFormat(int r, int g, int b) {
    if(r < 0 || r > 255) {
        printf("%s\n", "Nespravny vstup.");
        return EXIT_FAILURE;
    }

    if(g < 0 || g > 255) {
        printf("%s\n", "Nespravny vstup.");
        return EXIT_FAILURE;
    }

    if(b < 0 || b > 255) {
        printf("%s\n", "Nespravny vstup.");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void convertComponentsIntoHexadecimal(int r, int g, int b) {
    r <= 15 ? printf("#0%X", r) : printf("#%X", r);
    g <= 15 ? printf("0%X", g) : printf("%X", g);
    b <= 15 ? printf("0%X\n", b) : printf("%X\n", b);
}

int main() {
    int result, r, g, b;
    int end = EOF; // kontroluje, zda se za závorkou nevyskytuje ještě nějaký symbol/znak - podobně jako u zahřívací úlohy
    printf("%s\n", "Zadejte barvu v RGB formatu:");
    /**
     * Mezery jsou zde důležité, protože scanf bude považovat za platné následující vstupy:
     * rgb(0,255,255)
     * rgb(     0,          255,            255)
     * rgb      (       255,        25,     255)
     * atd...
     */
    result = scanf(" rgb ( %d , %d , %d )%n", &r, &g, &b, &end);
    if(validateInputFormat(result, end) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    if(validateRGBFormat(r, g, b) != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    }

    convertComponentsIntoHexadecimal(r, g, b);
    return EXIT_SUCCESS;
}