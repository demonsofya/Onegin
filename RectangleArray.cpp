// Случайно продолбалась с названием файла,
// короче это buffer в котором удалена вся фигня и заменены \n на \0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Txlib.h>

#include "RectangleArray.h"
#include "BiArray.h"

//char **text = (char *) calloc(

unsigned char *GetElement(unsigned char *data, int y, int x, int size_X) {

    assert(data);

    return (unsigned char *)((size_t)data + (y * size_X + x) * sizeof(unsigned char));
}

//-----------------------------------------------------------------------------

int FindLongestSring (FILE *file_ptr) {

    assert(file_ptr);

    fseek(file_ptr, SEEK_SET, 0);


    int max_size = 0;
    unsigned int symbol = 'a';
    int curr_size = 0;

    while(symbol != EOF) {

        if (symbol == '\n') {
            if (curr_size > max_size)
                max_size = curr_size;

//printf("max_size = %d, curr_size = %d\n", max_size, curr_size);

            curr_size = 0;
        } else {
            curr_size++;
        }

        symbol = fgetc(file_ptr);
//printf("symbol is %c\n", symbol);
    }

    return max_size;
}

int StringsFileCount (FILE *file_ptr) {

    assert(file_ptr);

    fseek(file_ptr, SEEK_SET, 0);
    int counter = 0;
    unsigned int symbol = 0;

    while(symbol != EOF) {

        if (symbol == '\n')
            counter++;

        symbol = fgetc(file_ptr);
    }

    return counter;
}

//-----------------------------------------------------------------------------


unsigned char* MakeRectangleArray(FILE *file_ptr, int file_size, int longest_string_size) {

    assert(file_ptr);

    fseek(file_ptr, SEEK_SET, 0);

    unsigned char *buffer_ptr = (unsigned char *) calloc(file_size, sizeof(unsigned char)*longest_string_size);
    assert(buffer_ptr);

    for (int y = 0; y < file_size; y++) {
        unsigned int symbol = 0;
        int x = 0;
        while (symbol != '\n') {

            symbol = fgetc(file_ptr);
            *GetElement(buffer_ptr, y, x, longest_string_size) = symbol;
            //printf("%c", symbol);

            x++;
        }

        *GetElement(buffer_ptr, y, x, longest_string_size) = '\0';
    }
//PrintArr(rectangle_ptr, file_size, longest_string_size); // отладочное

    return buffer_ptr;
}

//-----------------------------------------------------------------------------

unsigned char* MakeBufferArray(FILE *file_ptr, int *file_size, int *longest_size) {

    assert(file_ptr);
    assert(file_size);
    assert(longest_size);

    fseek(file_ptr, SEEK_SET, 0);

    int curr_size = 1;
    *file_size = 0;
    *longest_size = 0;

    unsigned char *buffer_ptr = (unsigned char *) calloc(1, sizeof(unsigned char));
    assert(buffer_ptr);

    int curr_symbol = 0, curr_position = 0;

    while (curr_symbol != EOF) {
        int curr_string_size = 0;

        while (curr_symbol != '\n' && curr_symbol != EOF) {

            if (curr_size <= curr_position) {

                curr_size = curr_size * 2;
                (unsigned char *) realloc(buffer_ptr, curr_size*sizeof(unsigned char));

                assert(buffer_ptr);
            }

            curr_symbol = fgetc(file_ptr);
            buffer_ptr[curr_position++] = curr_symbol;
            //printf("%c", symbol);

            curr_string_size++;
        }

        if (curr_string_size > *longest_size)
            *longest_size = curr_string_size;

        if (curr_size <= curr_position) {

            curr_size = curr_size * 2;
            buffer_ptr = (unsigned char *) realloc(buffer_ptr, curr_size*sizeof(unsigned char));

            assert(buffer_ptr);
        }

        buffer_ptr[curr_position++] = '\0';
        *file_size++;
    }
//PrintArr(rectangle_ptr, file_size, longest_string_size); // отладочное

    return buffer_ptr;
}

void PrintBufferArray(unsigned char *data, int size_Y) {

    assert(data);

    int curr_position = 0;

    for (int y = 0; y < size_Y; y++) {

        while (data[curr_position] != '\0') {
            printf("%c", data[curr_position]);
            curr_position++;
        }
        curr_position++;

        printf("\n");
    }
}

void PrintArr(unsigned char *data, int size_Y, int size_X) {

    assert(data);

    for (int y = 0; y < size_Y; y++) {

        for (int x = 0; x < size_X && *GetElement(data, y, x, size_X) != '\0'; x++) {
            fprintf(stderr, "%c", *GetElement(data, y, x, size_X));
        }

        printf("\n");
    }
}


//-----------------------------------------------------------------------------вот та хуйня не особо

