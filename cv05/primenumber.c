#include <stdio.h>
#include <stdlib.h>

int isPrimeNumber(int n) {
    int counter = 0;

    printf("%s\n", "-----------------------------");
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            printf("%d / %d = %d\n", n, i, n % i);
            counter++;
        }
    }
    printf("%s\n", "-----------------------------");

    return (counter == 2) ? 1 : 0;
}

int main() {
    int n;
    printf("%s\n", "Zadejte přirozené číslo (alespoň 2): ");

    if(scanf("%d", &n) != 1 || n < 2) {
        printf("%s\n", "Nesprávný vstup");
        return EXIT_FAILURE;
    }

    printf("Číslo %d %s prvočíslo\n", n, isPrimeNumber(n) ? "JE" : "NENÍ");

    return EXIT_SUCCESS;
}