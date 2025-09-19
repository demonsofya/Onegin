#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED

struct StringsInfo {

    char *string_ptr;
    int string_size;
};

struct StringsInfo *GetStructArray(char *buffer, size_t buffer_size);
char *GetBuffer(const char *file_name, size_t *file_size);
int StringsCount(char *buffer);

#endif // BUFFER_H_INCLUDED
