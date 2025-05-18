#include <stdio.h>


/***********************************************
Author: Dr. Adams
Date: <9/16/24>
Answer to question: <Insert the answer to
the following question: What happens if
the integer that you use as an argument
 is too big? Say 500000?>

Ans: It will cause a integer overflow.

***********************************************/

void recursive_down_to_zero(int num);
void recursive_up_to_int(int num);

int main(int argc, char* argv[]){
    recursive_down_to_zero(5000000000);
    printf("****\n");
    recursive_up_to_int(5000000000);
    return 0;
}

void recursive_down_to_zero(int num){
    if(num >= 0){
        printf("%d\n",num);
        recursive_down_to_zero(num-1);
    }
    return;
}

void recursive_up_to_int(int num){
    if(num >=0){
        recursive_up_to_int(num-1);
        printf("%d\n",num);
    }
    return;
} 