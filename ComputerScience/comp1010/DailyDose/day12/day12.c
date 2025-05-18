#include <stdio.h>

/***********************************************
Author: Shubh Patel
Date: < Oct-2-2024>
Purpose: < A rock, Paper Scissor game that you can play between two players >
Time Spent: < 35min >
***********************************************/

char choice(int player);
void determine_winner(char player1, char player2);
char play_again_fn(void);
void clear_keyboard_buffer();
int main(int argc, char* argv[]){
    char player1, player2, play_again;
   do{
        player1 = choice(1);
        player2 = choice(2);
        determine_winner(player1,player2);
        play_again = play_again_fn();
    }while(play_again == 'y' || play_again == 'Y');
    
    return 0;
}

char play_again_fn(){
    char play_again;
    do{
        printf("Do you wish to continue? (y/n) :");
        scanf(" %c", &play_again);
        clear_keyboard_buffer();
        if(play_again != 'y' && play_again == 'Y' && play_again != 'n' && play_again != 'N'){
            printf("I'm sorry but you must enter either 'y' or 'n'\n");
        }

    }while(play_again != 'y' && play_again != 'Y' && play_again != 'n' && play_again != 'N');
    return play_again;
}

void determine_winner(char player1, char player2){

    if ((player1 == 'P' || player1 == 'p') && (player2 == 'R' || player2 == 'r')){
        printf("Paper covers rock. Player one wins!\n");
    }else if ((player2 == 'P' || player2 == 'p') && (player1 == 'R' || player1 == 'r')){
        printf("Paper covers rock. Player two wins!\n");
    }else if ((player1 == 'P' || player1 == 'p') && (player2 == 'S' || player2 == 's')){
       printf("Scissor cut paper. Player two wins!\n");
    }else if ((player2 == 'P' || player2 == 'p') && (player1 == 'S' || player1 == 's')){
       printf("Scissor cut paper. Player one wins!\n");
    }else if ((player1 == 'R' || player1 == 'r') && (player2 == 'S' || player2 == 's')){
       printf("Rock breaks scissors. Player one wins!\n");
    }else if ((player1 == 's' || player1 == 'S') && (player2 == 'r' || player2 == 'R')){
       printf("Rock breaks scissors. Player two wins!\n");
    }else{
        printf("Draw, nobody wins\n");
    }
}
char choice(int player){
    char choice;
    printf("Player %d its your turn!,\nPlease choose (r)Rock, (p)aper, or (s)issors :",player);
    do{
        scanf(" %c", &choice);
        clear_keyboard_buffer();
        if(choice != 'p'&& choice != 'P'&& choice != 'r'&& choice != 'R'&& choice != 'S'&& choice != 's'){
            printf("I'm sorry but you must enter \'r\', \'p\', or \'s\'\nPlease choose (r)Rock, (p)aper, or (s)issors :");

        }
    }while(choice != 'p' && choice != 'P' && choice != 'r' && choice != 'R' && choice != 'S' && choice != 's');
    return choice;
}

void clear_keyboard_buffer(){
    char c;
    scanf("%c",&c);
    while(c != '\n'){
        scanf("%c",&c);
    }
}
