#ifndef POINTERARRAY_H_INCLUDED
#define POINTERARRAY_H_INCLUDED

void PrintPointerArray(unsigned char **text, int size_Y);
void GetPointerArray(FILE *file_ptr, unsigned char **text, int size_Y);
int get_line(unsigned char **lineptr, int *n, FILE *stream);
void ReadPoem_wrong (FILE *file_ptr, int size_Y, int size_X, unsigned char **text);

#endif // POINTERARRAY_H_INCLUDED
