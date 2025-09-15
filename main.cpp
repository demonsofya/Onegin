#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Txlib.h>
//#include <ctupe.h>
#include <string.h>

//#include "RectangleArray.h"
//#include "BiArray.h"
//#include "PointerArray.h"

/*void PrintBiArray(unsigned char *text, const int size_Y, const int size_X);
void GetBiArray(FILE *file_ptr, int size_Y, int size_X, unsigned char *text);
int strcmp_modified(const unsigned char *str_first, const unsigned char *str_second);
void SwapStrings(unsigned char *text, const int size_Y, const int size_X, int y_first, int y_second);

int str_unsigned_len(const unsigned char *str) {  // TODO: поделить на файлики

    int len = 0;

    while(str[len] != '\0') {
        len++;
    }

    return len;
}
//=============================================================================

/*int FindLongestSring (FILE *file_ptr);
void PrintArr (char *data, int size_Y, int size_X);
int StringsFileCount (FILE *file_ptr);
char* MakeRectangleArray (FILE *file_ptr, int file_size, int longest_string_size);
char *GetElement (char *data, int y, int x, int size_X);

char *GetElement(char *data, int y, int x, int size_X) {
    return (char *)((size_t)data + (y * size_X + x) * sizeof(char));
}

//-----------------------------------------------------------------------------

int FindLongestSring (FILE *file_ptr) {

    assert(file_ptr);

    fseek(file_ptr, SEEK_SET, 0);


    int max_size = 0;
    int symbol = 'a';
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
    int symbol = 0;

    while(symbol != EOF) {

        if (symbol == '\n')
            counter++;

        symbol = fgetc(file_ptr);
    }

    return counter;
}

//-----------------------------------------------------------------------------


char* MakeRectangleArray(FILE *file_ptr, int file_size, int longest_string_size) {

    assert(file_ptr);

    fseek(file_ptr, SEEK_SET, 0);

    char *rectangle_ptr = (char *) calloc(file_size, sizeof(char)*longest_string_size);
    assert(rectangle_ptr);

    for (int y = 0; y < file_size; y++) {
        int symbol = 0;
        int x = 0;
        while (symbol != '\n') {

            symbol = fgetc(file_ptr);
            *GetElement(rectangle_ptr, y, x, longest_string_size) = symbol;
            //printf("%c", symbol);

            x++;
        }

        *GetElement(rectangle_ptr, y, x, longest_string_size) = '\0';
    }
//PrintArr(rectangle_ptr, file_size, longest_string_size); // отладочное

    return rectangle_ptr;
}

void PrintArr(char *data, int size_Y, int size_X) {

    assert(data);

    for (int y = 0; y < size_Y; y++) {

        for (int x = 0; x < size_X && *GetElement(data, y, x, size_X) != '\0'; x++) {
            fprintf(stderr, "%c", *GetElement(data, y, x, size_X));
        }

        printf("\n");
    }
}

*//*
//=============================================================================

// Работает, проверено
void GetBiArray(FILE *file_ptr, int size_Y, int size_X, unsigned char *text) {

    assert(file_ptr);
    assert(text);

    fseek(file_ptr, SEEK_SET, 0);

    for (int y = 0; y < size_Y; y++) {

        int x = 0;
        unsigned int curr_symbol = fgetc(file_ptr);

        while (curr_symbol != '\n' && curr_symbol != EOF) {
            *GetElement(text, y, x, size_X) = curr_symbol;
            curr_symbol = fgetc(file_ptr);
            x++;
        }

        *GetElement(text, y, x, size_X) = '\0';
    }
}

// Работает, проверено
void PrintBiArray(unsigned char *text, const int size_Y, const int size_X) {

    assert(text);

    for (int y = 0; y < size_Y; y++) {

        int x = 0;

        while (*GetElement(text, y, x, size_X) != '\0' && x < size_X) {
            printf("%c", *GetElement(text, y, x, size_X));
            x++;
        }

        printf("\n");
    }
    printf("\n");
}

// Положительно число если второе больше, отрицательное иначе
int strcmp_modified(const unsigned char *str_first, const unsigned char *str_second) {

    int position_first = 0;
    int position_second = 0;

    while (position_second < str_unsigned_len(str_second) && position_second < str_unsigned_len(str_second)) {

        while (isspace(str_first[position_first]) || str_first[position_first] == '.'
               || str_first[position_first] == ',' || str_first[position_first] == '-'
               || str_first[position_first] == '!' || str_first[position_first] == '?')
            position_first++;

        while (isspace(str_second[position_second]) || str_second[position_second] == '.'
               || str_second[position_second] == ',' || str_second[position_second] == '-'
               || str_second[position_second] == '!' || str_second[position_second] == '?')
            position_second++;

        if (str_first[position_first] != str_second[position_second])
            break;
        else {
            position_first++;
            position_second++;
        }
    }

/*
printf("second string sembol = %c %d, \nfirst string symbol = %c %d\nРазница = %d",
        str_second[position_second], str_second[position_second],
        str_first[position_first], str_first[position_first],
        str_second[position_second] - str_first[position_first]);
*//*

    return (int(str_second[position_second] - str_first[position_first]));

}

// Работает, проверено
void SwapStrings(unsigned char *text, const int size_Y, const int size_X, int y_first, int y_second) {

    for (int x = 0; x < size_X; x++) {
        int curr_symbol = *GetElement(text, y_first, x, size_X);

        *GetElement(text, y_first, x, size_X) = *GetElement(text, y_second, x, size_X);
        *GetElement(text, y_second, x, size_X) = curr_symbol;
    }
} */
/*void PrintPointerArray(unsigned char **text, int size_Y);
void GetPointerArray(FILE *file_ptr, unsigned char **text, int size_Y);

size_t get_line(unsigned char **lineptr, size_t *n, FILE *stream) {
    size_t string_size = 1;
    unsigned char *pointer = (unsigned char *) calloc(string_size, sizeof(char));

    *n = 0;
    unsigned char readen_symbol = '\0';

    assert(pointer);

    while ((readen_symbol = fgetc(stream)) != '\0' &&
            readen_symbol != '\n' &&
            readen_symbol != EOF) {

        if (*n >= string_size - 1) {
            size_t new_string_size = string_size * 2;

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
        size_t curr_size = 0;
        size_t *n = &curr_size;
        get_line(&text[y], n, file_ptr);
        printf("strinng number %d is %s\n", y+1, text[y]);
    }


    PrintPointerArray(text, size_Y);
}

void PrintPointerArray(unsigned char **text, int size_Y) {

    for (int y = 0; y < size_Y; y++)
        printf("%s\n", text[y]);

}*/

//-----------------------------------------------------------------------------

#define end_of_file

unsigned char* MakeBufferArray(FILE *file_ptr, int *file_size) {

    assert(file_ptr);
    assert(file_size);

    fseek(file_ptr, SEEK_SET, 0);

    int curr_size = 10;
    *file_size = 0;

    unsigned char *buffer_ptr = (unsigned char *) calloc(1, 10*sizeof(unsigned char));
    assert(buffer_ptr);

    int curr_symbol = 0, curr_position = 0;

    while (curr_symbol != EOF) {

        int curr_string_size = 0;

        while (curr_symbol != '\n' && curr_symbol != EOF) {

            if (curr_size <= curr_position) {

                curr_size = curr_size * 2;
                buffer_ptr = (unsigned char*) realloc(buffer_ptr, curr_size * sizeof(unsigned char));

                assert(buffer_ptr);
            }

            curr_symbol = fgetc(file_ptr);
            buffer_ptr[curr_position++] = curr_symbol;
            fprintf(stderr, "%c", curr_symbol);

            curr_string_size++;
        }

        if (curr_size <= curr_position) {

            curr_size = curr_size * 2;
            buffer_ptr = (unsigned char*) realloc(buffer_ptr, curr_size*sizeof(unsigned char));
            printf("curr size %d curr position %d\n", curr_size, curr_position);

            assert(buffer_ptr);
        }

        if (curr_symbol == '\n')
            curr_symbol = '\0';

        buffer_ptr[curr_position++] = '\0';
        *file_size++;
    }
//PrintArr(rectangle_ptr, file_size, longest_string_size); // отладочное
    if (curr_size <= curr_position + 1) {

        curr_size = curr_size * 2;
        buffer_ptr = (unsigned char*) realloc(buffer_ptr, curr_size*sizeof(unsigned char));

        assert(buffer_ptr);
    }
    curr_symbol = EOF;

    buffer_ptr[++curr_position] =  '`';   // Вот это костыль, чтобы обозначить конец файла
    fprintf(stderr, "\n\n");              // Наверное стоит хранить адрес конца
    return buffer_ptr;
}

void PrintBufferArray(unsigned char *data, int size_Y) {

    assert(data);

    int curr_position = 0;

    while (data[curr_position] != '`') {

        while (data[curr_position] != '\0' && data[curr_position] != '`') {

            fprintf(stderr, "%c", data[curr_position]);
            curr_position++;

        }
        if (data[curr_position] != EOF)
            curr_position++;
        else
            break;

        printf("\n");
    }
}

//-----------------------------------------------------------------------------


int main()
{
    FILE *Onegin_ptr = fopen("C:\\Users\\sonya\\OneDrive\\Documentos\\GitHub\\Onegin\\Array varinats\\PushkinOnegin_new_short.txt", "r");
    printf("%p", Onegin_ptr);

    /*int file_size = StringsFileCount(Onegin_ptr);
    int longest_string_size = FindLongestSring(Onegin_ptr);
    printf("longest srting = %d\nstring count = %d\n", longest_string_size, file_size);

    //printf("\n\n%d", longest_string_size);
    unsigned char *rectangle_onegin_ptr = MakeRectangleArray(Onegin_ptr, file_size, longest_string_size);

//PrintArr(rectangle_onegin_ptr, file_size, longest_string_size); // отладочное
    //char BiArray[5983][48] = {};
    unsigned char *BiArray = (unsigned char *) calloc(file_size, sizeof(int)*longest_string_size);
    GetBiArray(Onegin_ptr, file_size, longest_string_size, BiArray);
//PrintBiArray(BiArray, file_size, longest_string_size);

    PrintBiArray(BiArray, 10, longest_string_size);
    SwapStrings(BiArray, 10, longest_string_size, 1, 2);
    PrintBiArray(BiArray, 10, longest_string_size);

    const unsigned char first_string[] = "Привет, мирф";
    const unsigned char second_string[] = "Приветмир";

    int comparing_result = strcmp_modified(first_string, second_string);
    if (comparing_result > 0)
        printf("Второе больше\n");
    else if (comparing_result < 0)
        printf("Первое больше\n");
    else
        printf("Одинаково\n");

    unsigned char **pointer_array_ptr = (unsigned char**) calloc(1, 10*sizeof(char *));
    GetPointerArray(Onegin_ptr, pointer_array_ptr, 10); */

    int string_count = 1;
    unsigned char *buffer_ptr = MakeBufferArray(Onegin_ptr, &string_count);

    assert(buffer_ptr);

    PrintBufferArray(buffer_ptr, string_count);

    free(buffer_ptr);
    fclose(Onegin_ptr);

    return 0;
}
