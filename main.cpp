#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

#include "buffer.h"
#include "sort.h"
#include "output.h"

int main()
{

    size_t buffer_size = 0;
    size_t long_buffer_size = 0;

    char *buffer = GetBuffer("Onegin_short.txt", &buffer_size);
    char *buffer_long = GetBuffer("PushkinOnegin_English_new.txt", &long_buffer_size);
//printf("%s\n", buffer);
//printf("buffer size is %d\n", buffer_size);

    int text_size = StringsCount(buffer);
    StringsInfo *text = GetStructArray(buffer, text_size);

    int long_text_size = StringsCount(buffer_long);
    StringsInfo *long_text = GetStructArray(buffer_long, long_text_size);

//printf("text size is %d\n", text_size);
    // TODO: rename

//for (int i = 0; i < text_size; i++)
//printf("%s\n\n", text[i]);

    BubbleSort_FromBegin(text, text_size);
    FILE *output_file = fopen("Onegin_output.txt", "w");
    FILE *output_second_file = fopen("Onegin_output_second.txt", "w");
    FILE *output_comporator_file = fopen("Onegin_output_comporator.txt", "w");
    PutTextInFile(output_file, text, text_size);
    PutTextInFile_Strings(output_second_file, text, text_size);


    BubbleSort_FromEnd(text, text_size);
    PutTextInFile(output_file, text, text_size);
    PutTextInFile_Strings(output_second_file, text, text_size);

    fprintf(output_file, "%s", buffer);
    fprintf(output_second_file, "%s", buffer);



    BubbleSort_WithCompareFunc(text, text_size, strcmp_modified_english);
    PutTextInFile_Strings(output_comporator_file, text, text_size);
    BubbleSort_WithCompareFunc(text, text_size, strcmp_modified_english_from_end);
    PutTextInFile_Strings(output_comporator_file, text, text_size);

    FILE *output_long_file = fopen("Onegin_output_full.txt", "w");
    BubbleSort_FromBegin(long_text, long_text_size);
    PutTextInFile_Strings(output_long_file, long_text, long_text_size);
    BubbleSort_FromEnd(long_text, long_text_size);
    PutTextInFile_Strings(output_long_file, long_text, long_text_size);
    fprintf(output_long_file, "%s", buffer_long);


    free(buffer);
    fclose(output_file);
    fclose(output_second_file);
    fclose(output_comporator_file);
    fclose(output_long_file);
    return 0;
}
