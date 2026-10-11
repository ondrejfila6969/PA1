#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int x;
    printf("%s\n", "ml' nob:");

    if(scanf("%d", &x) != 1) {
        printf("%s\n", "Neh mi'");
        return EXIT_FAILURE;
    }
    int c;
    /**
     * Kontroluje, znak po znaku, dokud je různý od nového řádku a současně konce souboru/chybě při čtení
     * '' zde musí být, protože tyto uvozovky značí char
     * -> porovnáváme číselnou hodnotu c s (EOF = -1)
     */
    while((c = getchar()) != '\n' && c != EOF) {
        /**
         * Pokud následující znak není bílý (vyhodí se chyba)
         * např. zadám 1.abcd (následující znak po 1 - . není bílý znak, vyhodí se chyba) - tu jedničku zpracuje scanf nad while cyklem
         */
        if(!isspace((unsigned char) c)) {
            printf("%s\n", "bIjatlh 'e' yImev");
            return EXIT_FAILURE;
        }
    }

    if((x < 0) || (x > 8)) {
        printf("%s %d\n", "Qih mi'", x);
        return EXIT_FAILURE;
    }
    
    printf("%s\n", "Qapla'");
    switch(x) {
        case 0:
            printf("%s\n", "noH QapmeH wo' Qaw'lu'chugh yay chavbe'lu' 'ej wo' choqmeH may' DoHlu'chugh lujbe'lu'.");
            break;
        case 1:
            printf("%s\n", "bortaS bIr jablu'DI' reH QaQqu' nay'.");
            break;
        case 2:
            printf("%s\n", "Qu' buSHa'chugh SuvwI', batlhHa' vangchugh, qoj matlhHa'chugh, pagh ghaH SuvwI''e'.");
            break;
        case 3:
            printf("%s\n", "bISeH'eghlaH'be'chugh latlh Dara'laH'be'.");
            break;
        case 4:
            printf("%s\n", "qaStaHvIS wa' ram loS SaD Hugh SIjlaH qetbogh loD.");
            break;
        case 5:
            printf("%s\n", "Suvlu'taHvIS yapbe' HoS neH.");
            break;
        case 6:
            printf("%s\n", "Ha'DIbaH DaSop 'e' DaHechbe'chugh yIHoHQo'.");
            break;
        case 7:
            printf("%s\n", "Heghlu'meH QaQ jajvam.");
            break;
        case 8:
            printf("%s\n", "leghlaHchu'be'chugh mIn lo'laHbe' taj jej.");
            break;
    }
    return EXIT_SUCCESS;
}