#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Txlib.h>
//#include <ctupe.h>
#include <string.h>

#include "RectangleArray.h"
#include "BiArray.h"
#include "PointerArray.h"

// Неправильная версия
void ReadPoem_wrong (FILE *file_ptr, int size_Y, int size_X, unsigned char **text) {

    assert(file_ptr);
    assert(text);

    fseek(file_ptr, SEEK_SET, 0);

    unsigned char *str = (unsigned char *) calloc(1, size_X*sizeof(char));

    for (int y = 0; y < size_Y; y++) {

        get_line(&str, &size_X, file_ptr);
        text[y] = str;
    }


    PrintPointerArray(text, size_Y);
}

int get_line(unsigned char **lineptr, int *n, FILE *stream) {

    assert(lineptr);
    assert(stream);
    assert(n);

    int string_size = 1;
    unsigned char *pointer = (unsigned char *) calloc(string_size, sizeof(char));
    assert(pointer);

    *n = 0;
    unsigned char readen_symbol = '\0';

    assert(pointer);

    while ((readen_symbol = fgetc(stream)) != '\0' &&
            readen_symbol != '\n' &&
            readen_symbol != EOF) {

        if (*n >= string_size - 1) {
            int new_string_size = string_size * 2;

            pointer = (unsigned char*) realloc(pointer, new_string_size * sizeof(unsigned char));
            string_size = new_string_size;
        }

        assert(pointer);

        pointer[*n] = readen_symbol;
        (*n)++;

//fprintf (stderr, "*n = %d, string_size = %d\n", *n, (int) string_size);
    }

    if (*n >= string_size - 1) {
        pointer = (unsigned char*) realloc(pointer, string_size * 2 * sizeof(unsigned char));
    }

//fprintf (stderr, "*n = %d, string_size = %d\n", *n, (int) string_size);

    pointer[*n] = '\0';
    *lineptr = pointer;

    return *n + 1;
}

void GetPointerArray(FILE *file_ptr, unsigned char **text, int size_Y) {

    assert(file_ptr);
    assert(text);

    fseek(file_ptr, SEEK_SET, 0);

    for (int y = 0; y < size_Y; y++) {
        int curr_size = 0;
        int *n = &curr_size;
        get_line(&text[y], n, file_ptr);
        printf("strinng number %d is %s\n", y+1, text[y]);
    }


    PrintPointerArray(text, size_Y);
}

void PrintPointerArray(unsigned char **text, int size_Y) {

    assert(text);

    for (int y = 0; y < size_Y; y++)
        printf("%s\n", text[y]);

}
