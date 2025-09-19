#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "buffer.h"

int strcmp_modified_english_from_end(const char *str_first, const char *str_second,
                            int str_first_len, int str_second_len);

int strcmp_modified_english(const char *str_first, const char *str_second,
                            int str_first_len, int str_second_len);

int strcmp_modified_russian(const char *str_first, const char *str_second,
                            int str_first_len, int str_second_len);

void BubbleSort_FromBegin(struct StringsInfo *ptr_array, size_t array_size);

void BubbleSort_FromEnd(struct StringsInfo *ptr_array, size_t array_size);

void BubbleSort_WithCompareFunc(struct StringsInfo *ptr_array, size_t array_size,
                                int (*compare_func)(const char *str_first,const char *str_second,
                                                    int str_first_len, int str_second_len));

int strcmp_begin_Qsort(void *param1, void *param2);

int strcmp_end_Qsort(void *param1, void *param2);

#endif // SORT_H_INCLUDED
