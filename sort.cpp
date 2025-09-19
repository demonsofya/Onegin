#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "buffer.h"
#include "sort.h"

int strcmp_modified_english_from_end(const char *str_first, const char *str_second,
                            int str_first_len, int str_second_len) {

    assert(str_first);
    assert(str_second);

    int position_first = str_first_len - 1;
    int position_second = str_second_len - 1;

    while (position_first > 0 && position_second > 0
            && str_first[position_first] != '\n' && str_second[position_second] != '\n'
            && str_first[position_first] != '\0' && str_second[position_second] != '\0') {

        while (!isalpha(str_first[position_first]) && position_first > 0)
            position_first--;

        while (!isalpha(str_second[position_second]) && position_second > 0)
            position_second--;


        if ((tolower(str_first[position_first]) != tolower(str_second[position_second]))) {
            return (int(tolower(str_second[position_second]) - tolower(str_first[position_first])));

        } else {
            position_first--;
            position_second--;
        }
    }

    return (int(tolower(str_second[position_second]) - tolower(str_first[position_first])));

}


//-----------------------------------------------------------------------------


int strcmp_modified_english(const char *str_first, const char *str_second,
                            int str_first_len, int str_second_len) {

    assert(str_first);
    assert(str_second);

    int position_first = 0;
    int position_second = 0;

    while (position_first < str_first_len && position_second < str_second_len
            && str_first[position_first] != '\n' && str_second[position_second] != '\n'
            && str_first[position_first] != '\0' && str_second[position_second] != '\0') {

        while (!isalpha(str_first[position_first]) && position_first < str_first_len)
            position_first++;

        while (!isalpha(str_second[position_second]) && position_second < str_second_len)
            position_second++;


        if ((tolower(str_first[position_first]) != tolower(str_second[position_second]))) {
            return (int(tolower(str_second[position_second]) - tolower(str_first[position_first])));

        } else {
            position_first++;
            position_second++;
        }
    }

    return (int(tolower(str_second[position_second]) - tolower(str_first[position_first])));

}

int strcmp_modified_russian(const char *str_first, const char *str_second,
                            int str_first_len, int str_second_len) {

    assert(str_first);
    assert(str_second);

    int position_first = 0;
    int position_second = 0;

    while (position_first < str_first_len && position_second < str_second_len) {

            while (isspace(str_first[position_first]) || str_first[position_first] == '.'
                || str_first[position_first] == ','   || str_first[position_first] == '-'
                || str_first[position_first] == '!'   || str_first[position_first] == '?')
                   position_first++;

            while (isspace(str_second[position_second]) || str_second[position_second] == '.'
                || str_second[position_second] == ','   || str_second[position_second] == '-'
                || str_second[position_second] == '!'   || str_second[position_second] == '?')
                   position_second++;

            if (tolower(str_first[position_first]) != tolower(str_second[position_second])) {
                break;

            } else {
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

    return (int(tolower(str_second[position_second]) - tolower(str_first[position_first])));

}


//=============================================================================


void BubbleSort_FromBegin(struct StringsInfo *ptr_array, size_t array_size) {

    assert(ptr_array);

    int result = 0;

    for (int i = 0; i < array_size; i++) {

        for (int j =  0; j < array_size - i - 1; j++) {

//printf("curr string is %s AND %s \n", ptr_array[j].string_ptr,  ptr_array[j + 1].string_ptr);
//printf("curr sizes are %d AND %d \n\n\n", ptr_array[j].string_size, ptr_array[j + 1].string_size);

            if ((result = strcmp_modified_english(ptr_array[j].string_ptr,  ptr_array[j + 1].string_ptr,
                                                  ptr_array[j].string_size, ptr_array[j + 1].string_size)) < 0) {

                struct StringsInfo help_ptr = ptr_array[j];

                ptr_array[j] = ptr_array[j + 1];
                ptr_array[j + 1] = help_ptr;
            }
        }
    }
}


void BubbleSort_FromEnd(struct StringsInfo *ptr_array, size_t array_size) {

    assert(ptr_array);

    int result = 0;

    for (int i = 0; i < array_size; i++) {

        for (int j =  0; j < array_size - i - 1; j++) {

//printf("curr string is %s AND %s \n", ptr_array[j].string_ptr,  ptr_array[j + 1].string_ptr);
//printf("curr sizes are %d AND %d \n\n\n", ptr_array[j].string_size, ptr_array[j + 1].string_size);


            if ((result = strcmp_modified_english_from_end(ptr_array[j].string_ptr,  ptr_array[j + 1].string_ptr,
                                                  ptr_array[j].string_size, ptr_array[j + 1].string_size)) < 0) {

                struct StringsInfo help_ptr = ptr_array[j];

                ptr_array[j] = ptr_array[j + 1];
                ptr_array[j + 1] = help_ptr;
            }
        }
    }
}

void BubbleSort_WithCompareFunc(struct StringsInfo *ptr_array, size_t array_size,
                                int (*compare_func)(const char *str_first,const char *str_second,
                                                    int str_first_len, int str_second_len)) {

    assert(ptr_array);

    int result = 0;

    for (int i = 0; i < array_size; i++) {

        for (int j =  0; j < array_size - i - 1; j++) {

//printf("curr string is %s AND %s \n", ptr_array[j].string_ptr,  ptr_array[j + 1].string_ptr);
//printf("curr sizes are %d AND %d \n\n\n", ptr_array[j].string_size, ptr_array[j + 1].string_size);

            if ((result = compare_func(ptr_array[j].string_ptr,  ptr_array[j + 1].string_ptr,
                                                  ptr_array[j].string_size, ptr_array[j + 1].string_size)) < 0) {

                struct StringsInfo help_ptr = ptr_array[j];

                ptr_array[j] = ptr_array[j + 1];
                ptr_array[j + 1] = help_ptr;
            }
        }
    }
}


//-----------------------------------------------------------------------------

int strcmp_begin_Qsort(void *param1, void *param2) {

    assert(param1);
    assert(param2);

    const char* str_first = *(char **) param1;
    const char* str_second = *(char **) param2;

    int position_first = 0;
    int position_second = 0;

    while (str_first[position_first] != '\n' && str_second[position_second] != '\n'
            && str_first[position_first] != '\0' && str_second[position_second] != '\0') {

        while (!isalpha(str_first[position_first]) && str_first[position_first] != '\n' && str_first[position_first] != '\0')
            position_first++;

        while (!isalpha(str_second[position_second]) && str_second[position_second] != '\n' && str_second[position_second] != '\0')
            position_second++;


        if ((tolower(str_first[position_first]) != tolower(str_second[position_second]))) {
            return (int(tolower(str_second[position_second]) - tolower(str_first[position_first])));

        } else {
            position_first++;
            position_second++;
        }
    }

    return (int(tolower(str_second[position_second]) - tolower(str_first[position_first])));

}

int strcmp_end_Qsort(void *param1, void *param2) {

    assert(param1);
    assert(param2);

    int position_first = 0;
    int position_second = 0;

    const char* str_first = *(char **) param1;
    const char* str_second = *(char **) param2;

    while (str_first[position_first] != '\n' && str_first[position_first] != '\0')
        position_first++;

    while (str_second[position_second] != '\n' && str_second[position_second] != '\0')
        position_second++;

    position_first--;
    position_second--;

    while (position_first > 0 && position_second > 0
            && str_first[position_first] != '\n' && str_second[position_second] != '\n'
            && str_first[position_first] != '\0' && str_second[position_second] != '\0') {

        while (!isalpha(str_first[position_first]) && position_first > 0)
            position_first--;

        while (!isalpha(str_second[position_second]) && position_second > 0)
            position_second--;


        if ((tolower(str_first[position_first]) != tolower(str_second[position_second]))) {
            return (int(tolower(str_second[position_second]) - tolower(str_first[position_first])));

        } else {
            position_first--;
            position_second--;
        }
    }

    return (int(tolower(str_second[position_second]) - tolower(str_first[position_first])));

}


//=============================================================================


