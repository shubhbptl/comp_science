#include "stack.h"
#include <stdio.h>

int test_case_is_valid(STACK hMy_stack);

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
            while (stack_is_empty(stack) != TRUE) {
              stack_pop(stack);
            }
          }
    }

    stack_destroy(&stack);
    return 0;
}
