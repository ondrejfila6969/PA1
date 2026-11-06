#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;

}

bool isArrayReversed(int * array1, int * reversedArray, int size) {
    qsort(reversedArray, size, sizeof(int), compare);

    int counter = 0;
    for(int i = 0; i < size; i++) {
        if(reversedArray[i] == array1[i]) {
            counter++;
        }
    }
    return counter == size;
}

int main() {
    int array1[] = {1, 2, 3, 4};
    int array2[] = {4, 3, 2, 1};
    int size = (sizeof(array2) / sizeof(array2[0]));

    printf("Pole1 %s reverzní vůči 2. poli\n", isArrayReversed(array1, array2, size) ? "JE" : "NENÍ");

}