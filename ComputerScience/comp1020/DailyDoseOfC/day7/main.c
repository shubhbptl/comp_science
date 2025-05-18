#include "stack.h"
#include <stdio.h>

/**********************************************************************
Program: <Parenthesis Balancer>
Author: <Shubh Patel>
Date: <02/23/25>
Time spent: <6hr>
Purpose: The purpose of this program is to tell if the parenthesis are balanced or not.
***********************************************************************/

int main() {
    int n;
    int i;
    STACK stack = stack_init_default();

    scanf("%d", &n);
    clear_keyboard_buffer();
    for (i = 0; i < n; i++) {
        if (test_case_is_valid(stack) == 1) {
            printf("Yes\n");
        } else {
            printf("No\n");
            while (!stack_is_empty(stack)) {
                stack_pop(stack);
            }
        }
    }
    stack_destroy(&stack);
    return 0;
}
