
#include <stdio.h>
/***********************************************
Author: Shubh Patel
Date: < sep-18-2024 >
Purpose: < practice recurision as well as binary using math >
***********************************************/
void print_binary(int num);
int main(int argc, char *argv[])
{

    print_binary(0);
    return 0;
}
void print_binary(int num)
{
    if(num == 0){
        printf("%d", 0);
    }   
    if (num > 0)
    {
        if(num/2 != 0){
        print_binary(num / 2);
        }
        printf("%d", num % 2);
    }
}