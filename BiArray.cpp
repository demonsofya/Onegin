#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Txlib.h>
//#include <ctupe.h>
#include <string.h>

#include "RectangleArray.h"
#include "BiArray.h"

// работает
int str_unsigned_len(const unsigned char *str) {

    assert(str);

    int len = 0;

    while(str[len] != '\0') {
        len++;
    }

    return len;
}

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

void GetBiArray_WithFgets(FILE *file_ptr, int size_Y, int size_X, unsigned char *text) {

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
// Для того, чтобы работало пришлось написать все в беззнаковых
int strcmp_modified(const unsigned char *str_first, const unsigned char *str_second) {

    assert(str_first);
    assert(str_second);

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
*/

    return (int(str_second[position_second] - str_first[position_first]));

}

// Работает, проверено
void SwapStrings(unsigned char *text, const int size_Y, const int size_X, int y_first, int y_second) {

    assert(text);

    for (int x = 0; x < size_X; x++) {
        int curr_symbol = *GetElement(text, y_first, x, size_X);

        *GetElement(text, y_first, x, size_X) = *GetElement(text, y_second, x, size_X);
        *GetElement(text, y_second, x, size_X) = curr_symbol;
    }

}
