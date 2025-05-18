#include <stdio.h>

/***********************************************************
Author: <Shubh Patel>
Date: <1/24/2025>
Effort: <3 min>
Purpose: <Purpose of this assignment is to explore the use left shift operator.>
***********************************************************/

int main(int argc, char* argv[]){

    unsigned int x = 1;

    for(int i = 0; x != 0; i++){
        printf("%d: %u\n",i,x);
        x = x << 1;
    }
    return 0;
}

/*
Diagram Example
   ↓ 00000010 ←
   0 ^^^^^^^  0
   0|        |0
   0|        |0
   0|        |0

*/ 