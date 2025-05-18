#include <stdio.h>

/***********************************************
Author: Dr. Adams
Date: < sep-23-2024 >
Answer to question: <Insert the answer to
the following question: What happens if
the integer that you type is again big?
Say 500000? Why is this behavior different
 than what you saw with your daily6?>

output: < Daily6 uses recursion which store all the call back on stacks which overflow your memory if number is too larger,
while this program store data temporary in stack and releases after it has been print, which don't not consume more stack space. >
***********************************************/

void loop_down_to_zero(int num);
void loop_up_to_int(int num);

int main(int argc, char* argv[]){
    int num;
    printf("Please enter a positive integer: ");
    scanf("%d",&num);
    loop_down_to_zero(num);
    printf("****\n");
    loop_up_to_int(num);
    return 0;
}

void loop_down_to_zero(int num){
    while (num >= 0){
        printf("%d\n",num);
        num--;
    }
}
void loop_up_to_int(int num){
        int x =0;
        while(x<=num){
        printf("%d\n",x);
        x++;
    }
}