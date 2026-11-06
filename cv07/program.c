#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


typedef struct ARRAY {
    int * data;
    int size;
    int capacity;
} T_ARRAY;

void createArray(T_ARRAY * array) {
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}

void addElement(T_ARRAY * array, int value) {
    if(array->size == array->capacity) {
        int newCapacity;

        if(array->capacity == 2) {
            newCapacity = 2;
        } else {
            newCapacity = array->capacity * 2;
        }
        int * newData = realloc(array->data, newCapacity * sizeof(int));

        if(newData == NULL) {
            printf("%s\n", "Invalid memory allocation.");
            return;
        }

        array->data = newData;
        array->capacity = newCapacity;
    }

    array->data[array->size] = value;
    array->size++;
}

void printArray(T_ARRAY *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }

    printf("\n");
}

int main() {

    T_ARRAY array;

    createArray(&array);

    addElement(&array, 10);
    addElement(&array, 20);
    addElement(&array, 30);
    addElement(&array, 40);

    printArray(&array);

    free(array.data);
    
    return EXIT_SUCCESS;
}