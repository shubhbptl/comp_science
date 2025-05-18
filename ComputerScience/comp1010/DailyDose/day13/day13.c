#include <stdio.h>

/***********************************************
Author: <Shubh Patel>
Date: < Oct-7-2024>
Purpose: <A small game Rock Paper Scissor using enum.>
Time Spent: < 25 min>
***********************************************/


enum choice {PAPER, SCISSOR, ROCK};
typedef enum choice Choice;

Choice choice(int player);
void determine_winner(Choice player1,Choice player2);
char play_again_fn(void);
void clear_keyboard_buffer(void);

int main(){
    Choice player1, player2;
    char play_again;

    do{
        player1 = choice(1);
        player2 = choice(2);
        determine_winner(player1,player2);
        play_again = play_again_fn();
    }while(play_again == 'y' || play_again == 'Y');
    return 0;
}

void determine_winner(Choice player1,Choice player2){
    if(player1 == player2){
        printf("Draw, nobody wins\n");
    }else if((player1 == ROCK && player2 == SCISSOR) ||
            (player1 == PAPER && player2 == ROCK) ||
            (player1 == SCISSOR && player2 == PAPER)){
            if(player1 == ROCK){
                printf("Rock breaks scissors! Player 1 wins!\n");
            }else if(player1 == PAPER){
                printf("Paper covers Rock! Player 1 wins!\n");
            }else if(player1 == SCISSOR){
                printf("Scissor cut Paper! Player 1 wins!\n");
            }
    }else{
            if(player2 == ROCK){
                printf("Rock breaks scissors! Player 2 wins!\n");
            }else if(player2 == PAPER){
                printf("Paper covers Rock! Player 2 wins!\n");
            }else if(player2 == SCISSOR){
                printf("Scissor cut Paper! Player 2 wins!\n");
            }     
        }
    }

char play_again_fn(void){
    char play_again;
    printf("Do you wish to continue? (y/n) :");
    do{
        scanf(" %c", &play_again);
        clear_keyboard_buffer();
        if(play_again != 'y' && play_again != 'Y' && play_again != 'n' && play_again != 'N'){
            printf("I'm sorry but you must enter either 'y' or 'n'\n");
            printf("Do you wish to continue? (y/n) :");
        }

    }while(play_again != 'y' && play_again != 'Y' && play_again != 'n' && play_again != 'N');
    return play_again;
}

Choice choice(int player){
    char choice;
    printf("Player %d its your turn!,\nPlease choose (r)Rock, (p)aper, or (s)issors : ",player);
    do{
        scanf(" %c", &choice);
        clear_keyboard_buffer();
        switch(choice){
        case 'p':
        case 'P':
            return PAPER;
            break;
        case 'r':
        case 'R':
            return ROCK;
            break;
        case 's':
        case 'S':
            return SCISSOR;
            break;
        default:
            printf("I'm sorry I do not understand \nPlease enter your choice (p)aper, (r)ock, (s)cissors: ");
        }
    }while(choice != 'p' && choice != 'P' && choice != 'r' && choice != 'R' && choice != 'S' && choice != 's');
        return ROCK;
    }

void clear_keyboard_buffer(void){
    char c;
    scanf("%c",&c);
    while(c != '\n'){
        scanf("%c",&c);
    }
}