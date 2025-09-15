#ifndef BIARRAY_H_INCLUDED
#define BIARRAY_H_INCLUDED

void PrintBiArray(unsigned char *text, const int size_Y, const int size_X);
void GetBiArray(FILE *file_ptr, int size_Y, int size_X, unsigned char *text);
int strcmp_modified(const unsigned char *str_first, const unsigned char *str_second);
void SwapStrings(unsigned char *text, const int size_Y, const int size_X, int y_first, int y_second);


#endif // BIARRAY_H_INCLUDED
