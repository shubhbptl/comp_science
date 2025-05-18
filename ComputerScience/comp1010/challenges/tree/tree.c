#include <stdio.h>
#include <stdlib.h>

int tree(int trees[], int size);

int main(int argc, char* argv[]){
    int trees[] = {10,8,9,10,1,2,3,4,5,6,7};// 1// -1,0,1,0,1,2,3,4,5,6
                // 0 1 2  0 0 0   0 0 0 0 0
    //int trees[] = {10,8,9,1,2,3,4,5,6,7}; 1 // 0,1,0,1,2,3,4,5,6,
    //int trees[] = {8,10,22,9,33,21,50,41,60};
    //int trees[] = {8,10,22,9,33,21,1,41,60};
    //               
    
    // int trees[] = {10,1,2,3,4,5,6,7,8,9};
    int size = sizeof(trees)/sizeof(trees[0]);
    tree(trees,size);
    return 0;
}

int tree(int trees[], int size){
    int smallest = trees[1];
    int keep = 0;
    int newList[size+10];
    for(int j =2; j <size+2; j++){
        if(trees[j] > smallest){
            keep++;
            newList[j] = trees[j-1];
        }
            smallest = trees[j];
    }
    // int newSmallest = newList[1];
    for(int i = 0; i< size; i++){    
        printf("%d ,",newList[i]);
        }
    return keep;
}

