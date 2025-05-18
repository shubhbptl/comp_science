#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

/***********************************************************
Author: <Shubh Patel>
Date: <02/08/2025>
Effort: <2hr>
Purpose: <Flip bits and create more bits if needed using opaque design.>
 Interface proposal: <A proposal function would be a toggle flag function which would flip the bit from 0 -> 1 or 1 -> 0 without
 needing to check and set manually.>
***********************************************************/

#define BITS_32 32
struct bit_flag{
    int size;
    int capacity;
    int* data;
};
typedef struct bit_flag Bit_Flag;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits){
    Bit_Flag* bits;
    bits = malloc(sizeof(Bit_Flag));
    if(bits != NULL){
        bits->size = (number_of_bits / BITS_32) + ((number_of_bits % BITS_32) != 0);
        bits->capacity = bits->size + 1;
        bits->data = malloc(sizeof(int)*bits->capacity);
        if(bits->data == NULL){
            free(bits);
            return NULL;
        }
    }
    return bits;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position){
    Bit_Flag* pBit_flags = (Bit_Flag*) hBit_flags;
    int index = flag_position / BITS_32;
    int position = flag_position % BITS_32;
    unsigned int bit_mask = 1 << position;
    if(flag_position < pBit_flags->size){
        pBit_flags->data[index] |= bit_mask;
        return SUCCESS;
    }
    if(index >= pBit_flags->capacity){
        int new_capacity = index + 1;
        int* new_data = (int*)malloc(sizeof(int) * new_capacity);
        if(new_data == NULL){
            return FAILURE;
        }   
        for (int i = 0; i < pBit_flags->size; i++)
        {
            new_data[i] = pBit_flags->data[i];
        }
        for(int i = pBit_flags->size; i < new_capacity; i++){
            new_data[i] = 0;
        }
        free(pBit_flags->data);
        pBit_flags->data = new_data;
        pBit_flags->capacity = new_capacity;
    }
        pBit_flags->size = index+1;
        pBit_flags->data[index] |= bit_mask;

    return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position){
    Bit_Flag* pBit_flags = (Bit_Flag*) hBit_flags;
    int index = flag_position / BITS_32;
    int position = flag_position % BITS_32;
    unsigned int temp = ~(1 << position);
    if (index < pBit_flags->size)
    {
        pBit_flags->data[index] &= temp;
        return SUCCESS;
    }
    if(index >= pBit_flags->capacity){
        int new_capacity = index + 1;
        int* new_data = (int*)malloc(sizeof(int) * new_capacity);
        if(new_data == NULL){
            return FAILURE;
        }   
        for (int i = 0; i < pBit_flags->size; i++)
        {
            new_data[i] = pBit_flags->data[i];
        }
        for(int i = pBit_flags->size; i < new_capacity; i++){
            new_data[i] = 0;
        }
        free(pBit_flags->data);
        pBit_flags->data = new_data;
        pBit_flags->capacity = new_capacity;
    }
        pBit_flags->size = index+1;
        pBit_flags->data[index] &= temp;
    return SUCCESS;


}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position){
    Bit_Flag* pBit_flags = (Bit_Flag*) hBit_flags;
    int index = flag_position / BITS_32;
    int position = flag_position % BITS_32;
    unsigned int temp = 1 << position;
    if(index >= pBit_flags->size){
        return -1;
    }
    return (pBit_flags->data[index] & temp) ? 1 : 0;

}

int bit_flags_get_size(BIT_FLAGS hBit_flags){
    Bit_Flag* pBit_flags = (Bit_Flag*)hBit_flags;
    return pBit_flags->size * BITS_32;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags){
    Bit_Flag* pBit_flags = (Bit_Flag*)hBit_flags;
    return pBit_flags->capacity * BITS_32;
}

void bit_flags_destroy(BIT_FLAGS *phBit_flags){
    Bit_Flag* pBit_flags = (Bit_Flag*) *phBit_flags;
    free(pBit_flags->data);
    free(pBit_flags);
    *phBit_flags = NULL;
}