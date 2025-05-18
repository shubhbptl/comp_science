#include <stdio.h>

/***********************************************
Author: Shubh Patel
Date: < sep-25-2024 >
Purpose: < It ask for negative integer user input. >
Time Spent: < 14 minutes >
***********************************************/

int check_negative(void);
void clear_keyboard_buffer(void);
int main(int argc, char* argv[]){
    int result;
    
    do{
        printf("Please enter a negative integer: ");
        result = check_negative();
    }while (result != 0);

    return 0;
}

int check_negative(void){
    int num;
    int result;
    result = scanf("%d",&num);
    clear_keyboard_buffer();
    while(result != 1 || num >= 0){
        printf("I'm sorry, you must enter a negative integer less than zero: ");
        return 1;
    }
    
    printf("The negative integer was: %d \n", num);
    return 0;
    }



void clear_keyboard_buffer(void){
    char c;
    scanf("%c", &c);
    if(c != '\n'){
        scanf("%c",&c);
    }
}