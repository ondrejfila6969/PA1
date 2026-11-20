#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

bool isReverse(int * array1, int size1, int * array2, int size2) {
    if(size1 != size2) {
        return false;
    }

    for(int i = 0; i < size1; i++) {
        if(array1[i] != array2[size2 - i - 1]) {
            return false;
        }
    }
    return true;
}

bool isReverseStr(const char * str1, const char * str2) {
    size_t size1 = strlen(str1);
    size_t size2 = strlen(str2);

    if(size1 != size2) {
        return false;
    }

    for(size_t i = 0; i < size1; i++) {
        if(str1[i] != str2[size2 - i - 1]) {
            return false;
        }
    }
    return true;
}

// můžu se po stringu pohybovat
/**
void printStr(const char * str) {
    while(*str != '\0') {
        printf("%c", *str);
        str++;
    }
}
 */

int main() {

    printf("%s\n", "Retezce");
    assert(isReverseStr("Ahoj", "johA"));
    assert(!isReverseStr("Ahoj", "joha"));
    assert(!isReverseStr("", "joha"));
    assert(isReverseStr("", ""));

    char str1[] = "Ahoj";
    char str2[] = "johA";

    isReverseStr(str1, str2);
    
    return EXIT_SUCCESS;
}