#include <stdio.h>

/***********************************************************
Author: <Shubh Patel>
Date: <1/28/25>
Effort: <1hr>
Purpose: <The program changes any bit to one by using bitwise operator and left shit operator>
***********************************************************/

void set_flag(unsigned int *pFlag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);

int main(int argc, char *argv[])
{
    unsigned int flag_holder = 0;
    int i;
    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);
    // printf("%u", flag_holder);
    for (i = 31; i >= 0; i--)
    {
        printf("%d", check_flag(flag_holder, i));
        if (i % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
void set_flag( unsigned int *pFlag_holder, int flag_position){
    unsigned int temp = 1;
    *pFlag_holder = (temp << flag_position) | *pFlag_holder;
}
int check_flag(unsigned int flag_holder, int flag_position){
    unsigned int temp = 1;
    temp = temp << flag_position;
    if((flag_holder & temp)>0){
        return 1;
    }
    return 0;
}