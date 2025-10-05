#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "size.h"

void size_file (Info_t *Meow) {
    assert(Meow);
    FILE *fp = Meow -> text;
    fseek(fp, 0L, SEEK_END);
    int symbols_count = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    Meow->symbols_count = symbols_count - 1;
}

void num_str (Info_t *Meow) {
    assert(Meow);
    int symbols_num = Meow -> symbols_count;
    char *arr = Meow -> buffer;
    int str_count = 1;
    for (int i = 0; i < symbols_num; i++) {
       if (arr[i] == '\n') {
            str_count += 1;
       }
    }
    Meow->lines_count = str_count;
}

int my_strlen (const char *str) {
    assert(str != NULL);
    int i = 0;
    assert(str != NULL);
    while (str[i] != '\0' && str[i] != '\n') {
        assert(str != NULL);
        i++;
    }
    return i;
}

int min_num(int a, int b) {
    return a < b ? a : b;
}
