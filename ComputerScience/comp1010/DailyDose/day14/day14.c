#include <stdio.h>


/***********************************************
Author: <Shubh Patel>
Date: <oct-29-2024>
Purpose: <create a program that as users input to convert between length and weight 
            until users presses 0 to exit program>
Sources of Help: <N/A.>
 Time Spent: <10min>
***********************************************/

void convert_lengths();
void convert_weights();
void clear_keyboard_buffer();
int main(int argc, char* argv[]){
    int user;
    int valid;
    do{
        printf("Type (1) to convert lengths, (2) to convert weights, and (0) to quit: ");
        valid = scanf("%d",&user);
        clear_keyboard_buffer();
        if(valid != 1){
            printf("Invalid input, Please enter 0, 1, or 2.\n");
              user = -1;
        }
        if(user == 1){
            convert_lengths();
        }else if (user == 2){
            convert_weights();
        }else if(user != 0 && valid == 1){
            printf("Invalid input, Please enter 0, 1, or 2.\n");
        }

    }while(user != 0);
    printf("Program terminated\n");
    return 0;
}

void convert_weights(){
    printf("Converting weights\n");
}
void convert_lengths(){
    printf("Converting lengths\n");
}
void clear_keyboard_buffer(){
    char c;
    scanf("%c",&c);
    while(c != '\n'){
        scanf("%c",&c);
    }
}