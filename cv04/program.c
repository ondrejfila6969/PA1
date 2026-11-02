#include <stdio.h>
#include <stdlib.h>

int main() {
    // for cyklus
    for(int i = 0; i < 5; i++) {
        printf("%d\n", i);
    }

    // ekvivalentní podoba for cyklu ve while cyklu
    int i = 0;
    while(i < 5) {
        printf("%d\n", i);
        i++;
    }

    return EXIT_SUCCESS;
}