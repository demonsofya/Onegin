#ifndef RECTANGLEARRAY_H_INCLUDED
#define RECTANGLEARRAY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Txlib.h>

int FindLongestSring (FILE *);
void PrintBufferArray(unsigned char *, int);
void PrintArr (unsigned char *, int, int);
int StringsFileCount (FILE *);
unsigned char* MakeRectangleArray (FILE *, int, int);
unsigned char *GetElement (unsigned char *, int, int, int);
unsigned char* MakeBufferArray(FILE *, int *, int *);



#endif // RECTANGLEARRAY_H_INCLUDED
