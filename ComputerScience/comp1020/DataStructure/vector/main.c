#include <stdio.h>
#include <stdlib.h>
#include "my_vector.h"
int main(int argc, char* argv[]){
    MY_VECTOR hVector;
    int i;

    hVector = my_vector_init_default();
    if(hVector == NULL){
        printf("Failed to allocate space for vector object.\n");
        exit(1);
    }
    for(i=0; i<10;i++){
        if(my_vector_push_back(hVector,i) == FAILURE){
            printf("Failed %d",i);
            exit(1);
        }
    }
    while (my_vector_is_empty(hVector) == FALSE)
    {
        my_vector_pop_back(hVector);
        printf("pop");
    }
    *my_vector_at(hVector,i) = 42;
    for(int i = 0; i< my_vector_get_size(hVector); i++){
        printf("%d",*my_vector_at(hVector,i));
    }
    //work
    my_vector_destroy(&hVector);

    return 0;
}