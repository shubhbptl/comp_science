#include <stdio.h>

/***********************************************************
Author: <Shubh Patel>
Date: <2/2/2025>
Effort: <30min>
Purpose: <This program can turn as many bits as you want by turning it into array.>
***********************************************************/

#define BITS_32 32;
void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char *argv[])
{
    unsigned int flag_holder[5] = {0}; // [0-31],[32-63],[64-95],[96-127],[128-159]

    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);
    display_flags(flag_holder, 5);
    printf("\n\n");
    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);
    display_flags(flag_holder, 5);

    return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position)
{
    unsigned int temp = 1;
    int index = flag_position / BITS_32;
    int position = flag_position % BITS_32;
    flag_holder[index] = (temp << position) | flag_holder[index];
}
void unset_flag(unsigned int flag_holder[], int flag_position)
{
    int index = flag_position / BITS_32;
    int position = flag_position % BITS_32;
    unsigned int temp = 1;
    temp = temp << position;
    if ((*flag_holder & temp) > 0)
    {
        *flag_holder = ~(temp) & *flag_holder;
    }
}

int check_flag(unsigned int flag_holder[], int flag_position)
{
    int index = flag_position / BITS_32;
    int position = flag_position % BITS_32;
    unsigned int temp = 1;
    temp = temp << position;
    if ((flag_holder[index] & temp) > 0)
    {
        return index;
    }
    return -1;
}
void display_flags_as_array(unsigned int flag_holder)
{
    unsigned int temp[1] = {flag_holder};
    int i = 0;
    do
    {
        printf("%d", check_flag(temp, i));
        i++;
        if (i % 4 == 0)
        {
            printf(" ");
        }
    } while (i <= 31);
    printf("\n");
}
void display_flags(unsigned int flag_holder[], int size)
{
    for (int i = 0; i < size; i++)
    {
        display_flags_as_array(flag_holder[i]);
    }
}
