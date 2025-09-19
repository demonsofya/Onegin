#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include "buffer.h"
#include <stdio.h>

void PrintStringInFile(FILE *file_ptr, char *string_ptr, int string_size);

void PutTextInFile(FILE *file_ptr, struct StringsInfo *ptr_array, size_t array_size);

void PutTextInFile_Strings(FILE *file_ptr, struct StringsInfo *ptr_array, size_t array_size);

void ChangeEntersToZeros(struct StringsInfo *ptr_array, size_t array_size);

void ChangeZeroToEnters(struct StringsInfo *ptr_array, size_t array_size);

#endif // OUTPUT_H_INCLUDED
