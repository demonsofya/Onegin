#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "buffer.h"
#include "output.h"


//-----------------------------------------------------------------------------


void PrintStringInFile(FILE *file_ptr, char *string_ptr, int string_size) {

    assert(file_ptr);
    assert(string_ptr);

    int curr_position = 0;

    // TODO: not %c

    while (string_ptr[curr_position] != '\n' && string_ptr[curr_position] != '\0' && curr_position < string_size) {

        fprintf(file_ptr, "%c", string_ptr[curr_position]);
//printf("%c", string_ptr[curr_position]);
        curr_position++;
    }

    fprintf(file_ptr, "\n");
}

void PutTextInFile(FILE *file_ptr, struct StringsInfo *ptr_array, size_t array_size) {

    assert(file_ptr);
    assert(ptr_array);

//fprintf(stderr, "|%zu|", array_size);

    for (int curr_pos = 0; curr_pos < array_size; curr_pos++)
        PrintStringInFile(file_ptr, ptr_array[curr_pos].string_ptr, ptr_array[curr_pos].string_size);

    fprintf(file_ptr, "\n\n\n");

}

//-----------------------------------------------------------------------------


void ChangeZeroToEnters(struct StringsInfo *ptr_array, size_t array_size) {
    for (int curr_pos = 1; curr_pos < array_size; curr_pos++) {
        *(ptr_array[curr_pos].string_ptr - 1) = '\n';
    }
}

void ChangeEntersToZeros(struct StringsInfo *ptr_array, size_t array_size) {
    for (int curr_pos = 1; curr_pos < array_size; curr_pos++) {
        *(ptr_array[curr_pos].string_ptr - 1) = '\0';
    }
}


//-----------------------------------------------------------------------------

void PutTextInFile_Strings(FILE *file_ptr, struct StringsInfo *ptr_array, size_t array_size) {

    assert(file_ptr);
    assert(ptr_array);

    ChangeEntersToZeros(ptr_array, array_size);

    for (int curr_pos = 0; curr_pos < array_size; curr_pos++) {
        fprintf(file_ptr, "%s", ptr_array[curr_pos]);
        fprintf(file_ptr, "\n");
    }

    fprintf(file_ptr, "\n\n\n");

    ChangeZeroToEnters(ptr_array, array_size);

}
