// #include <TXLib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "input.h"
#include "print.h"
#include "size.h"

int main() {
    Info_t letters = {};
    // if (letters.text == 0) {
    //     printf("Error in opening file");
    //     return 1;
    // }
    constructor_of_struct(&letters);
    return 0;

}
