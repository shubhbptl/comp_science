#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "my_string.h"
#include "generic_vector.h"
#include "avl_tree.h"
#include <time.h>

#define MAX_SIZE 30

GENERIC_VECTOR *init_dictionary( void ) ;
Boolean prompt_continue_game( void ) ;
Boolean prompt_running_total( void ) ;
int prompt_word_length( void ) ;
int prompt_number_of_guesses( void ) ;
char get_character( void ) ;
void clear_keyboard_buffer( void ) ;
void clear_screen( void ) ;
void hangman_driver( void ) ;

int main( int argc, char *argv[] ) {

    do {
      // game loop
    srand(time(0));
    hangman_driver() ;

    } while ( prompt_continue_game() ) ;

    return 0 ;

}

GENERIC_VECTOR *init_dictionary( void ) {

    GENERIC_VECTOR *hgVector = ( GENERIC_VECTOR * ) malloc( MAX_SIZE * sizeof( GENERIC_VECTOR ) ) ;
    MY_STRING hString = NULL ;
    FILE *fp ;
    int i ;

    fp = fopen( "dictionary.txt", "r" ) ;

    if ( fp == NULL ) exit( 1 ) ;

    for ( i = 0; i < MAX_SIZE; i++ ) {

        hgVector[i] = generic_vector_init_default( my_string_assignment, my_string_destroy ) ;

        if ( hgVector[i] == NULL ) exit( 1 ) ;
 
    }
      
    hString = my_string_init_default() ;

    if ( hString == NULL ) exit( 1 ) ;

    while ( my_string_extraction( hString, fp ) ) {

        if ( my_string_get_size( hString ) < 30 ) {

            if ( !generic_vector_push_back( hgVector[my_string_get_size( hString )], ( Item ) hString ) ) exit( 1 ) ;
    
        }

    }

    my_string_destroy( &hString ) ;
    fclose( fp ) ;

    return hgVector ;
}

Boolean prompt_continue_game( void ) {

    char c ;

    printf( "Would you like to play again? (y/n) " ) ;
    scanf( "%c", &c ) ;
    clear_keyboard_buffer() ;

    c = tolower( c ) ;

    if ( !isalpha( c ) || ( isalpha( c ) && c != 121 && c != 110 ) ) {

        return prompt_continue_game() ;

    }

    if ( c == 121 ) return TRUE ;
    if ( c == 110 ) return FALSE ;

    return FALSE ;

}

Boolean prompt_running_total( void ) {

    char c ;

    printf( "Would you like a running total of the number of words remaining? (y/n) " ) ;
    scanf( "%c", &c ) ;
    clear_keyboard_buffer() ;

    c = tolower( c ) ;

    if ( !isalpha( c ) || ( isalpha( c ) && c != 121 && c != 110 ) ) {

        return prompt_running_total() ;

    }

    if ( c == 121 ) return TRUE ;
    if ( c == 110 ) return FALSE ;

    return FALSE ;

}


int prompt_word_length( void ) {

    int d ;

    do {

        printf( "How many characters do you want the word to be? " ) ;
        scanf( "%d", &d ) ;
        clear_keyboard_buffer() ;

    } while ( d <= 2 || d >= MAX_SIZE ) ; 

    return d ;

}

int prompt_number_of_guesses( void ) {

    int d ;

    do {

        printf( "How many guesses do you want? " ) ;
        scanf( "%d", &d ) ;
        clear_keyboard_buffer() ;

    } while ( d <= 0 || d > 26 ) ; 

    return d ;

}

char get_character( void ) {

    char c ;

    printf( "\nGuess a character: " ) ;
    scanf( "%c", &c ) ;
    clear_keyboard_buffer() ;

    if ( isalpha( c ) ) {

        c = tolower( c ) ;
    
    } else {

        return get_character() ;

    }

    return c ;

}

void clear_keyboard_buffer( void ) {
    
    char c ;

    do {

        scanf( "%c", &c) ;

    } while ( c != '\n' ) ;
    
    return ;
}

void clear_screen( void ) {

    #ifdef _WIN32
        system( "cls" ) ;
    #elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
        system( "clear" ) ;
    #else
        #error "OS not supported"
    #endif

}

void hangman_driver( void ) {

    GENERIC_VECTOR *dictionary = init_dictionary() ;
    GENERIC_VECTOR largest_family = NULL ;
    TREE hTree = avl_tree_init_default() ;
    MY_STRING word_key = my_string_init_default() ;
    MY_STRING guess_list = my_string_init_c_string( " " ) ;
    MY_STRING word_family = my_string_init_default() ;
    int word_length, number_of_guesses, running_total, i ;
    char current_guess ;

    
    word_length = prompt_word_length() ;
    number_of_guesses = prompt_number_of_guesses() ;
    running_total = prompt_running_total() ;


    for ( i = 0; i < word_length; i++ ) my_string_push_back( word_key, '-' ) ;

    do {
        
        printf( "You have %d guess(es) remaining\nLetters used: ", number_of_guesses ) ;
        my_string_insertion( guess_list, stdout ) ;
        
        printf( "\nCurrent word: ") ;
        my_string_insertion( word_key, stdout ) ;

        do {

            current_guess = get_character() ;

        } while ( check_if_used( guess_list, current_guess ) ) ;

        my_string_push_back( guess_list, current_guess) ;
        my_string_push_back( guess_list, ',' ) ;
        my_string_push_back( guess_list, ' ' ) ;

        

        if ( running_total ) printf( "Running total of the number of words remaining:\n" ) ;

        for ( i = 0; i < generic_vector_get_size( dictionary[word_length] ); i++ ) {
   
            get_word_key_value( word_key, word_family, generic_vector_at( dictionary[word_length], i ), current_guess ) ;
            avl_tree_push( hTree, word_family, generic_vector_at( dictionary[word_length], i ) ) ;
   
        }

        largest_family = avl_tree_get_largest_family( hTree, running_total ) ;
        generic_vector_destroy( &( dictionary[word_length] ) ) ;
        dictionary[word_length] = generic_vector_init_default( my_string_assignment, my_string_destroy ) ;
        
        for ( i = 0; i < generic_vector_get_size( largest_family ); i++ ) {

            generic_vector_push_back( dictionary[word_length], generic_vector_at( largest_family, i ) ) ;

        }

        get_word_key_value( word_key, word_family, generic_vector_at( dictionary[word_length], 0 ), current_guess ) ;

        if ( my_string_compare( word_key, word_family ) == 0 ) {
            
            printf( "\nIncorrect. The word does not include any %c's\n\n", current_guess ) ;
            number_of_guesses-- ;
        
        }

        my_string_assignment( &word_key, word_family );

        generic_vector_destroy( &largest_family );
        avl_tree_destroy( &hTree ) ;
        my_string_destroy( &word_family ) ;
        word_family = my_string_init_default();
        hTree = avl_tree_init_default() ;

        if ( number_of_guesses == 0 ) {
          srand(time(0));
          printf("You lose!\nThe word was: ");
            my_string_insertion( generic_vector_at( dictionary[word_length], rand() % 10), stdout );
            printf( "\n\n" );
            break;

        }

        if ( my_string_compare( generic_vector_at( dictionary[word_length], 0 ), word_key ) == 0 ) {
            
            if ( generic_vector_get_size( dictionary[word_length] ) == 1) {
            
                printf( "You win!\nThe word was: ");
                my_string_insertion( generic_vector_at( dictionary[word_length], 0), stdout ) ;
                printf( "\n\n" ) ;
                break ;
            
            }

        }

    } while ( number_of_guesses > 0 ) ;

    avl_tree_destroy( &hTree ) ;
    my_string_destroy( &word_key ) ;
    my_string_destroy( &guess_list ) ;
    my_string_destroy( &word_family ) ;
    for ( i = 0; i < MAX_SIZE; i++ ) generic_vector_destroy( &dictionary[i] ) ;
    free( dictionary ) ;

}

