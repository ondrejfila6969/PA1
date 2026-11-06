#include <stdio.h>
#include <stdlib.h> // tady je uložen malloc
#include <stdbool.h>
#include <ctype.h>

typedef struct {
    int * data; // to bude pointer
    size_t capacity; // kapacita pole (lepší je používat typ size_t místo int)
    size_t size; // velikost pole
} Array;

Array createEmptyArray() {
    Array arr;

    arr.size = 0; // zpočátku bude pole mít velikost 0
    arr.capacity = 0;
    arr.data = nullptr;

    return arr;
}

/**
 * void initEmptyArray(Array * array) {

    }
 */

void growArray(Array * array) {
    /**
     *  // Nove pole o velikosti
        array->capacity = array->capacity + 1;
        // malloc
        int * tmp = (int *)malloc(array->capacity * sizeof(int));
        // Překopírovat prvky
        for(size_t i = 0; i < array->size; i++) {
            tmp[i] = array->data[i];
        }
        // TODO: Co uvolnit pamet?
        free(array->data);
        array->data = tmp;
     */

     // tohle je lepší řešení, má to lineární složitost !!!
    array->capacity = array->capacity * 2 + 1; 
    array->data = (int *)realloc(array->data, array->capacity * sizeof(int)); // realloc mi vrací nový ukazatel - musím si ho uložit
}

// vložení prvku na konec pole
// 1. kouknu se, jestli size >= capacity: Pokud jo, nafukuju
// 2. vložím prvek na konec
void pushArray(Array * array, int item) {
    if(array->size >= array->capacity) { // kontroluji, jestli je velikost vole větší nebo rovna kapacitě (pozor, array je pointer, musím použít šipku ->)
        growArray(array);
    }
    array->data[array->size] = item;
    array->size++;
}

void printArray(Array * array) {
    for(size_t i = 0; i < array->size; i++) {
        printf("%d \n", (array->data)[i]);
    }
}

void freeArray(Array * array) {
    free(array->data); // tohle je nutné
    array->data = nullptr; // tohle je nice to have
    array->capacity = 0;
    array->size = 0;
}

/*
void qsort( void* ptr, size_t count, size_t size,
            int (*comp)(const void*, const void*) );
    
            ptr <- ukazatele na zacatek pole
            count <- velikost jednoho prvku
            size <- velikost jednoho prvku
            int (*comp)(const void*, const void*) <- funkce, co porovnava 2 hodnoty
*/

int cmpIntDescending(const void* aa , const void* bb) {
    int a = *(const int*) aa;
    int b = *(const int*) bb;

    // return: -1 pokud prvek a je vetsi nez b
    // return: 0 pokud jsou stejne
    // return: 1 pokud a je mensi nez b

    if (a > b) return -1;
    if (a < b) return 1;
    return 0;
}

void sortDescArray(Array * arr) {
    qsort(arr->data, arr->size, sizeof(int), cmpIntDescending);
}

void popLastArray(Array * arr) {
    arr->size--;
}

int main() {
    Array arr = createEmptyArray(); // způsob č.1
    /*
    Array arr;
    initEmptyArray(&arr); // způsob č.2, je to to samý
    */
    for(int i = 0; i < 1000; i++) {
        pushArray(&arr, i);
    }
 
    printArray(&arr);
    sortDescArray(&arr);
    printArray(&arr);
    freeArray(&arr);

    return EXIT_SUCCESS;
}