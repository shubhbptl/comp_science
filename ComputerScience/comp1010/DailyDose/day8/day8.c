#include <stdio.h>

/***********************************************
Author: < Shubh Patel >
Date: < 9-20-2024 >
Purpose: < Purpose of this program is get to know how to take inputs and store it in variable. >
***********************************************/

int main(int argc, char* argv[]){
    int number;
    printf("Please enter a positive integer: ");
    scanf("%d", &number);
    
    if(number < 0){
        printf("not Valid Number");
    }
    else if(number % 2 == 0){
        number /= 2;
        printf("The next value of the number is: %d",number);
    }else{
        number = number * 3 + 1;
        printf("The next value of the number is: %d",number);
    }
    return 0;
}
