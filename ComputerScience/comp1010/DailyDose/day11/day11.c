#include <stdio.h>

/***********************************************
Author: < Shubh Patel >
Date: < Sep-30-2024 >
Purpose: <Program takes a number between range of 1 to 79 inclusive.>
Time Spent: < 20 min >
***********************************************/

int enter_number(int num);
void clear_keyboard_buffer(void);
void draw_line(int num);

int main(int argc, char* argv[]){
    int num;
    int result;
    
    do{
        printf("Please enter the number of asterisks you want in your line: ");
        result = scanf("%d", &num);
        clear_keyboard_buffer();
        if(result != 1){
            printf("Invalid input. Please enter a number between 1 and 79.\n");
        }
        num = enter_number(num);
        }while(result != 1 || num < 1 || num > 79);
        draw_line(num);
    return 0;
}

void draw_line(int num){
    for(int i = 0; i<num; i++){
        printf("*");
    }
    printf("\n");
}

int enter_number(int num){
    while(num < 1 || num > 79){
        printf("I'm sorry, that number is unrecognized or out of range, try [1-79]: ");
        scanf("%d",&num);
        clear_keyboard_buffer();
    }
    return num;
}

void clear_keyboard_buffer(){
    char c;
    scanf("%c",&c);
    while(c != '\n'){
        scanf("%c",&c);
    }
}
