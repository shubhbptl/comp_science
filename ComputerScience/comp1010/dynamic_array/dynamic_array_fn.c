#include <stdio.h>
#include <stdlib.h>

int* create_dynamic(int size){
    int* arr;
    arr = (int*) malloc(size * sizeof(int));
    return arr;
}
int main(int argc, char* argv[]){
    int size = 5;
    int num = 1234567;
    int rever = 0;
    int reminder;
    // int* dynamic = create_dynamic(size);

    // // for(int i =0; i<=size; i++){
    // //     dynamic[i] = i;
    // // }
    // for(int i =0; i< size; i++){
    //     printf("%d\n",dynamic[i]);
    // }

    while (num != 0)
    {
        rever *= 10;
        rever += num%10;
        num /= 10; 
    }
    

    printf("%d",rever);
    // free(dynamic);
    return 0;
}