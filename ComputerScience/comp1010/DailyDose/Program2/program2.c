#include <stdio.h>

/***********************************************
Author: <Shubh Patel>
Date: <11.9.2024>
Purpose: < find green crud population growth after certain amount of days >
Time Spent: <35min>
***********************************************/

void clear_keyboard_buffer();
void fibonacci(int green_crud, int days);
int input(int choice);
char run_fn(void);
int main(){
    int result;
    int green_crud;
    int days;
    char run;

    do{
        green_crud = input(1);
        days = input(2);
        fibonacci(green_crud,days);
        run = run_fn();

    }while(run == 'Y' || run == 'y');
    return 0;
}
int input(int choice){
    int result;
    int num;
    do{
    if(choice == 1){
        printf("Please enter the initial size of the green crud: ");
    }else{
        printf("Please enter the number of days: ");
    }
    result = scanf("%d", &num);
    clear_keyboard_buffer();
    if(!result || num < 0){
        printf("I'm sorry that value is unrecognized or is negative.\n");
    }
    }while(!result || num < 0);
    return num;
}

char run_fn(void){
    char run;
    do{
        printf("Do you wish to continue? (y/n) :");
        scanf(" %c", &run);
        clear_keyboard_buffer();
        if(run != 'y' && run != 'Y' && run != 'n' && run != 'N'){
            printf("I'm sorry but you must enter either 'y' or 'n'\n");
        }

    }while(run != 'y' && run != 'Y' && run != 'n' && run != 'N');
    return run;
}
void clear_keyboard_buffer(){
    char c;
    scanf("%c", &c);
    while(c != '\n'){
        scanf("%c", &c);
    }
}
void fibonacci(int green_crud, int days){
    
    int n,prev,curr,next,result;

    if (days < 0) {
        printf("Invalid number of days.\n");
        return;
    }

    n = days / 5;
    prev = green_crud; 
    curr = green_crud; 
    next = green_crud;

    for (int i = 2; i <= n; i++) {
        next = prev + curr; 
        prev = curr;        
        curr = next;
    }

    result = (n == 0) ? green_crud : curr;

    printf("With an initial population of %d pounds of crud growing for %d days, the final population would be %d pounds\n",green_crud,days,result);
}