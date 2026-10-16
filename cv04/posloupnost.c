#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

/**
 * Napište program, který od uživatele načítá
    způsobem
    n celých čísel,
    A vypisuje
    počet, součet, minimum, maximum, průměr čísel
 */

int validateInput(int result) {
    if(result != 1) {
        return EXIT_FAILURE;
    }

    int c;
    while((c = getchar()) != '\n' && c != EOF) {
        if(!isspace((unsigned char) c)) {
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

void printStats(int count, int min, int max, int sum, double avg) {
    printf("COUNT: %d\n", count);
    printf("MIN: %d\n", min);
    printf("SUM: %d\n", sum);
    printf("MAX: %d\n", max);
    printf("AVG: %lf\n", avg);
}

int main() {
    int n;
    int count = 0;
    int sum = 0;
    int max = INT_MIN;
    int min = INT_MAX;
    double avg;

    printf("%s\n", "Zadejte počet čísel n");
    int result = scanf("%d", &n);

    if(validateInput(result) != 0|| n < 0) {
        printf("%s\n", "Nespravny vstup.");
        return EXIT_FAILURE;
    }

    int n2;
    for(int i = 0; i < n; i++) {
        printf("%s\n", "Zadejte číslo: ");

        int result = scanf("%d", &n2);
        if(validateInput(result) != 0) {
            printf("%s\n", "Nespravny vstup.");
            return EXIT_FAILURE;
        }
        count++;
        sum += n2;

        (max < n2) ? max = n2 : max;
        (min > n2) ? min = n2 : min;
    }

    avg = ((double)sum / (double)n);
    printStats(count, min, max, sum, avg);

    return EXIT_SUCCESS;
}