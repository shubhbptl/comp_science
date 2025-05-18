#include <stdlib.h>
#include <stdio.h>
#include "bit_flags.h"

int main(int argc, char* argv[]){
    BIT_FLAGS bits;
    bits = bit_flags_init_number_of_bits(10);
    bit_flags_set_flag(bits,1);
    return 0;
}