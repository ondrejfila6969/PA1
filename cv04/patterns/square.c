#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int validateNumber(int result) {
    if(result != 1) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int ensureValidInput() {
    int c;
    while((c = getchar()) != '\n' && c != EOF) {
        if(!isspace((unsigned char) c)) {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int main() {
    int size;

    printf("%s\n", "Zadejte rozměr čtverce: ");
    int result = scanf("%d", &size);

    if(validateNumber(result) != 0 || ensureValidInput() != 0) {
        printf("%s\n", "Nespravny vstup.");
        return EXIT_FAILURE;
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%s ", "*");
        }
        printf("\n");
    }
}