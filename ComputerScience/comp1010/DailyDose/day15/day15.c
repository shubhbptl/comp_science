#include <stdio.h>

/***********************************************
Author: <Shubh Patel>
Date: <11.1.2024>
Purpose: <It asks for user response to convert lengths or weights.>
Sources of Help: <N/A>
Time Spent: <15min>
***********************************************/

void convert_lengths();
void length_to_metric();
void length_to_us();
void convert_weights();
void weight_to_metric();
void weight_to_us();
void clear_keyboard_buffer();

int main(int argc, char* argv[]){
    int user;
    do{
        printf("Type (1) to convert lengths, (2) to convert weights, and (0) to quit: ");
        if(scanf("%d", &user) != 1) {  
            printf("Invalid input, Please enter 0, 1, or 2.\n");
            clear_keyboard_buffer();  
            user = -1;  
        } else if(user == 1){
            convert_lengths();
        } else if (user == 2){
            convert_weights();
        } else if(user != 0){
            printf("Invalid input, Please enter 0, 1, or 2.\n");
        }
    } while(user != 0);

    printf("Program terminated\n");
    return 0;
}

void convert_weights(){
    int type_of_conversion;
    do{
        printf("Type (1) to convert pounds/ounces to kilograms/grams, (2) to convert kilograms/grams to pounds/ounces, (0) to quit: ");
        if(scanf("%d", &type_of_conversion) != 1) {
            printf("Invalid input, Please enter 0, 1, or 2.\n");
            clear_keyboard_buffer();
            type_of_conversion = -1;
        } else if(type_of_conversion == 1){
            weight_to_metric();
        } else if(type_of_conversion == 2){
            weight_to_us();
        } else if(type_of_conversion != 0){
            printf("Invalid input, Please enter 0, 1, or 2.\n");
        }
    } while(type_of_conversion != 0);
}

void convert_lengths(){
    int type_of_conversion;
    do{
        printf("Type (1) to convert feet/inches to meters/centimeters, (2) to convert meters/centimeters to feet/inches, (0) to quit: ");
        if(scanf("%d", &type_of_conversion) != 1) {
            printf("Invalid input, Please enter 0, 1, or 2.\n");
            clear_keyboard_buffer();
            type_of_conversion = -1; 
        } else if(type_of_conversion == 1){
            length_to_metric();
        } else if(type_of_conversion == 2){
            length_to_us();
        } else if(type_of_conversion != 0){
            printf("Invalid input, Please enter 0, 1, or 2.\n");
        }
    } while(type_of_conversion != 0);
}

void length_to_metric(){
    printf("Converting length to Metric\n");
}

void length_to_us(){
    printf("Converting length to Us\n");
}

void weight_to_metric(){
    printf("Converting weight to Metric\n");
}

void weight_to_us(){
    printf("Converting weight to Us\n");
}

void clear_keyboard_buffer(){
    char c;
    scanf("%c", &c);
    while(c != '\n'){
        scanf("%c", &c);
    }
}
