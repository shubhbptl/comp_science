#include <stdio.h>

char* reverse(char* array);

int main(int argc, char* argv[]){
    char word[] = "Happy Birthday!";
    printf("%s\n", word);
    reverse(word);
    printf("%s\n", word);
    printf("%s\n", reverse(word));
    printf("%s\n", word);
    return 0;
}
char* reverse(char* array){
    int start = 0;
    int end = 0;
    char temp = '\0';
    for(int i = 0; array[i] != '\0'; i++){
        end++;
    }
    end--;

    while(start<end){
        temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
    return array;
}