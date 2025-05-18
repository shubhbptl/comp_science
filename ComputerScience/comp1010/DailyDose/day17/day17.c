#include <stdio.h>
#include <stdlib.h>

/***********************************************
Author: <Shubh Patel>
Date: <Nov-13-2024>
Purpose: <Merge two file number into outfile in a ascending order>
Sources of Help: <N/A>
 Time Spent: <30min>
***********************************************/

void merge_file(FILE* input1, FILE* input2, FILE* output);
int main(){
    FILE* inp1;
    FILE* inp2;
    FILE* out;

    inp1 = fopen("input1.txt","r");
    inp2 = fopen("input2.txt","r");
    out = fopen("output.txt","w");
    if(inp1 == NULL|| inp2 == NULL || out == NULL){
        printf("Error: opening files");
        exit(1);
    }
    merge_file(inp1,inp2,out);
    fclose(inp1);
    fclose(inp2);
    fclose(out);
    return 0;
}
void merge_file(FILE* input1, FILE* input2, FILE* output){
    int noc1, noc2;
    int num1, num2;
    noc1 = fscanf(input1,"%d",&num1);
    noc2 = fscanf(input2,"%d",&num2);
    while(noc1 == 1 || noc2 == 1 ){
        if(noc1 == 1 && (noc2 != 1 || num1 <= num2)){
            fprintf(output, "%d\n", num1);
            noc1 = fscanf(input1, "%d", &num1);
        }else if(noc2 == 1){
            fprintf(output, "%d\n", num2);
            noc2 = fscanf(input2, "%d", &num2);
        }
    
    }
}