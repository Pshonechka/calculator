#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "print.h"

void printf_str(const char* str) {
    for(int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        putchar(str[i]);
    }
    putchar('\n');
}

void put_str(const char* str, Info_t *Meow) {
    FILE* fp = Meow -> ans;
    for(int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
        fputc(str[i], fp);
    }
    fputc('\n', fp);
}

void print_text(Info_t *Meow) {
    char** array = Meow -> array_of_pointers;
    int str_count = Meow -> lines_count;
    for (int i = 0; i < str_count; i++) {
        printf("line %d: ", i);
        printf_str(array[i]);
    }
}

void put_text(Info_t *Meow) {
    assert(Meow != NULL);
    assert(Meow->array_of_pointers != NULL);
    FILE* fp = Meow -> ans;

    char** array = Meow -> array_of_pointers;
    int str_count = Meow -> lines_count;
    for (int i = 0; i < str_count; i++) {
        put_str(array[i], Meow);
    }
    fputc('\n', fp);

}
