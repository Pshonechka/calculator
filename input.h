#ifndef INPUT_H
#define INPUT_H

// #include <TXLib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void constructor_of_struct(Info_t *Meow);
void read_text(Info_t *Meow);
void parse_text(Info_t *Meow);
int opening_file(FILE **to, const char* file_name, const char* method);
char *get_arr(Info_t *Meow);
void fill_pointer_arr(Info_t *Meow);

#endif // INPUT_H
