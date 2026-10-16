#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Prevents input is not equal to int
 */
int validateInput(int result) {
    if(result != 1) return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int ensureValidInput() {
    int c;
    while((c = getchar()) != '\n' && c != EOF) {
        if(!isspace((unsigned char) c)) {
            printf("%s\n", "Nespravny vstup.");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int main() {
    int num1, num2;

    printf("%s\n", "Zadejte první číslo: ");
    int result1 = scanf("%d", &num1);

    if(validateInput(result1) != 0) {
        printf("%s\n", "Nespravny vstup.");
        return EXIT_FAILURE;
    }

    if(ensureValidInput() != 0) {
        printf("%s\n", "Nespravny vstup.");
        return EXIT_FAILURE;
    } 

    printf("%s\n", "Zadejte druhé číslo: ");
    int result2 = scanf("%d", &num2);

    if(validateInput(result2) != 0) {
        printf("%s\n", "Nespravny vstup.");
        return EXIT_FAILURE;
    }

    if(ensureValidInput() != 0) {
        printf("%s\n", "Nespravny vstup.");
        return EXIT_FAILURE;
    } 

    // EUKLEIDŮV ALGORITMUS - 1) ODČÍTÁNÍ
    
    while(num1 != num2) {
        if(num1 > num2) {
            num1 -= num2;
        } else if (num2 > num1) {
            num2 -= num1;
        } else {
            printf("GCD cisel %d %d neexistuje\n", num1, num2);
        }
    }
    

    // EUKLEIDŮV ALGORITMUS - 2) ZBYTEK PO DĚLENÍ
    /*
    while(num2 != 0) {
        int r = num1 % num2;
        num1 = num2;
        num2 = r;
    }
    */
    
    printf("GCD: %d\n", num1);
    return EXIT_FAILURE;
}