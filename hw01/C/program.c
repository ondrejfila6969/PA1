#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void printResult(double result) {
    char output[32];
    // převede result na text a uloží do output array
    snprintf(output, sizeof(output), "%g", result);

    // strchr vyhledá v řetězci první znak e - pro exponent
    // je to pointer, který ukazuje na pozici znaku e -> index 3 v mém případě
    char *e = strchr(output, 'e');

    // pokud znak exponentu se ve výsledku nachází a na 2. pozici je +/- operace (10 na minus něco)
    if(e != NULL && (e[1] == '+' || e[1] == '-')) {
        // dokud je na 3. pozici 0 a současně na následující pozici není konec 
        while(e[2] == '0' && e[3] != '\0') {
            // prováděj posun doleva
            memmove(e + 2, e + 3, strlen(e + 3) + 1);
        }
    }

    printf("%s\n", output);
}

int main() {
    double num1, num2;
    char operation;
    char equation;
    printf("%s\n", "Zadejte vzorec:");

    if(scanf(" %lf %c %lf %c", &num1, &operation, &num2, &equation) != 4 || equation != '=') {
        printf("%s\n", "Nespravny vstup.");
        return EXIT_FAILURE;
    }

    int c;
    while((c = getchar()) != '\n' && c != EOF) {
        if(!isspace((unsigned char) c)) {
            printf("%s\n", "Nespravny vstup.");
            return EXIT_FAILURE;
        }
    }
    switch(operation) {
        case '+':
            // formát %g v kombinaci s doublem odstraní všechny přebytečné nuly ! (např. 3.5 + 1.5 = 5 místo 5.00000)
            printResult(num1 + num2);
            break;
        case '-':
            printResult(num1 - num2);
            break;
        case '*':
            printResult(num1 * num2);
            break;
        case '/':
            if(num2 != 0) {
                // trunc z knihovny math zachová celočíselný podíl
                printResult(trunc(num1 / num2)); 
                break;
            } else {
                printf("%s\n", "Nespravny vstup.");
                return EXIT_FAILURE;
            }
        default:
            printf("%s\n", "Nespravny vstup.");
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}