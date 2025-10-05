#ifndef STRUCT_H
#define STRUCT_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Info {
    FILE *text;
    char *buffer;
    char ** array_of_pointers;
    size_t lines_count;
    size_t symbols_count;
    FILE *ans;

} Info_t;

#endif // STRUCT_H
