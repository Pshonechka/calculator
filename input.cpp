#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "input.h"
#include "size.h"

void constructor_of_struct(Info_t *Meow) {
    opening_file(&Meow -> text, "commands.txt", "rb");
    opening_file(&Meow -> ans, "answers.txt", "wb");
    size_file(Meow);
    read_text(Meow);
    parse_text(Meow);
}

void read_text(Info_t *Meow) {
    char *book = get_arr(Meow);
    Meow -> buffer = book;
    num_str(Meow);
}

void parse_text(Info_t *Meow) {
    int str_count = Meow -> lines_count;
    Meow -> array_of_pointers = (char**) calloc((str_count+1), sizeof(char*));
    fill_pointer_arr(Meow);
}

int opening_file(FILE **to, const char* file_name, const char* method) {
    *to = fopen(file_name, method);
    if (*to == 0) {
        printf("Error in opening file");
        return 1;
    }
    return 0;
}

char *get_arr(Info_t *Meow) {
    int symbols_num = Meow -> symbols_count;
    FILE *fp = Meow -> text;
    char *ptr = (char*) calloc(symbols_num + 1, sizeof(char));
    if (ptr == NULL) {
        printf("Error in creating array\n");
        return NULL;
    }

    size_t read_size = fread(ptr, sizeof(char), symbols_num, fp);

    if (read_size != (size_t) symbols_num) {
        printf("read_size = %u\n", read_size);
        printf("symbols_num = %d\n", symbols_num);
        printf("Array sizes aren't equal\n");
        return NULL;
    }

    ptr[symbols_num] = '\0';
    return ptr;
}

void fill_pointer_arr(Info_t *Meow) {
    char ** array_of_ptr = Meow -> array_of_pointers;
    char *from = Meow -> buffer;
    array_of_ptr[0] = from;
    int symbols_num = Meow -> symbols_count;
    int str_count = Meow -> lines_count;
    int x = 0;
    for (int i = 0; i < symbols_num-1; i++) {
        if (from[i] == '\n') {
            x++;
            if (x < str_count) {
                array_of_ptr[x] = from+i+1;
            }
            else {
                printf("number of lines is bigger then number of ptrs!!!! FIX RN!!!!\n");
                exit(1);
                break;
            }
        }
    }
}


