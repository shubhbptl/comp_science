#include <stdio.h>

/***********************************************************
Author: <Shubh Patel>
Date: <1/29/25>
Effort: <5min>
Purpose: <To create 2 more function which unset bit from one to zero and create a own function for display.>
***********************************************************/

void set_flag(unsigned int *flag_holder, int flag_position);
void unset_flag(unsigned int *flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

int main(int argc, char *argv[])
{
    unsigned int flag_holder = 0;
    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);
    display_32_flags(flag_holder);
    unset_flag(&flag_holder, 31);
    unset_flag(&flag_holder, 3);
    set_flag(&flag_holder, 9);
    display_32_flags(flag_holder);
    return 0;
}

void set_flag(unsigned int *pFlag_holder, int flag_position)
{
    unsigned int temp = 1;
    *pFlag_holder = (temp << flag_position) | *pFlag_holder;
}
void unset_flag(unsigned int *flag_holder, int flag_position){
    unsigned int temp = 1;
    temp = temp << flag_position;
     if ((*flag_holder & temp) > 0)
    {
        *flag_holder = ~(temp) & *flag_holder;
    }
}

int check_flag(unsigned int flag_holder, int flag_position)
{
    unsigned int temp = 1;
    temp = temp << flag_position;
    if ((flag_holder & temp) > 0)
    {
        return 1;
    }
    return 0;
}
void display_32_flags(unsigned int flag_holder){
    int i;
    for (i = 31; i >= 0; i--)
    {
        printf("%d", check_flag(flag_holder, i));
        if (i % 4 == 0)
        {
            printf(" ");
        }
    }
    printf("\n");
}
