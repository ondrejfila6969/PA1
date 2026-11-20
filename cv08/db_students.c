#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char * username; // max.delku neznam
    int year;
    double avg;
} Student;

bool readStudent(Student* s) {
    char * line;
    size_t len;

    if(getline(&line, &len, stdin) == -1) {
        return false;
    }

    char * space = strchr(line, ' ');

    if(space == nullptr) {
        return false;
    }

    if(sscanf(space + 1, "%d %lf", &s->year, &s->avg) != 2) {
        return false;
    }

    *space = '\0'; // na tomhle místě je konec stringu
    s->username = strdup(line);

    return true;
}

void printStudent(const Student* s) {
    printf("Student: %s, %d, %lf\n", s->username, s->year, s->avg);
}

typedef struct {
    Student* data;
    size_t capacity;
    size_t size;
} ArrayStudent; 

void init(ArrayStudent * arr) {
    arr->data = nullptr;
    arr->size = 0;
    arr->capacity = 0;
}

void grow(ArrayStudent * arr) {
    arr->capacity = arr->capacity * 2 + 1;
    arr->data = (Student *)realloc(arr->data, arr->capacity * sizeof(Student));
}

void addStudent(ArrayStudent * arr, const Student * s) {
    if(arr->size >= arr->capacity) {
        grow(arr);
    }

    arr->data[arr->size] = *s;
    arr->size++;
}

void printArray(ArrayStudent * arr) {
    for(size_t i = 0; i < arr->size; i++) {
        printStudent(&arr->data[i]);
    }
}

void freeArray(ArrayStudent * arr) {
    for(size_t i = 0; i < arr->size; i++) {
        free(&arr->data[i]);
    }
    init(arr); // vynulování výchozích hodnot
}

int main() {
    ArrayStudent arr;
    init(&arr);

    Student s;
    while(readStudent(&s)) {
        addStudent(&arr, &s);
    }

    printArray(&arr);
    freeArray(&arr);
 
    return EXIT_SUCCESS;
}
