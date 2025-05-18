#include <stdio.h>

/***********************************************
Author: <Shubh Patel>
Date: <Oct-28-24>
Purpose: <This program finds the number of times it takes to reach 1 using a specified starting number and rule:
 if the number is even, divide by 2; if odd, multiply by 3 and add 1.>
Time Spent: <30min>
***********************************************/

void process(int start, int end);
void clear_keyboard_buffer(void);
int main(int argc, char* argv[]){
    int starting = 0;
    int ending = 0;
    int valid_input;

    do {
        printf("Enter a starting point: ");
        valid_input = scanf("%d", &starting);
        clear_keyboard_buffer();
        
        if(valid_input != 1 || starting <= 1 || starting >= 1000) {
            printf("Invalid input. Please enter a number less than 1000.\n");
        }

    } while (valid_input != 1 || starting <= 1 || starting >= 1000);

    do {
        printf("Enter an ending point: ");
        valid_input = scanf("%d", &ending);
        clear_keyboard_buffer();
        
        if (valid_input != 1 || ending <= starting || ending >= 10000) {
            printf("Invalid input. The ending point should be greater than starting and less than 10000.\n");
        }
    } while (valid_input != 1 || ending <= starting || ending >= 10000);

    process(starting, ending);

    return 0;
}

void clear_keyboard_buffer(void){
    char c;
    scanf("%c",&c);
    while(c != '\n'){
        scanf("%c",&c);
    }
}


void process(int start, int end){
    int column = 7;
    int count_column = 0;

    for (int i = start; i <= end; i++) {
        int count_until_one = 0;
        int num = i;

        while (num != 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num = num * 3 + 1;
            }
            count_until_one++;
        }

        printf("%5d:%-5d", i, count_until_one);
        count_column++;

        if (count_column == column) {
            printf("\n");
            count_column = 0;
        }
    }
    if (count_column != 0) {
        printf("\n");
    }
}
