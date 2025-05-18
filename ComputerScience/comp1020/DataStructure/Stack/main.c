#include "stack.h"
#include <stdio.h>
// #include <stdlib.h>

void clear_keyboard_buffer(void);

int main(int argc, char *argv[]) {
  // problem 673 in online judge
  //  signup virtual judge
  int n;
  int i;
  STACK stack;
  stack = stack_init_default();
  scanf("%d", &n);
  clear_keyboard_buffer();
  for (i = 0; i < n; i++) {
    if (test_case_is_valid(stack) == 1) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  /* STACK hStack;

   hStack = stack_init_default();
   if(hStack == NULL){
       printf("Failed to allocated space");
       exit(1);
   }
   if(stack_is_empty(hStack)){
       printf("Woof");
   }
   for(int i = 0; i<10; i++){
       if(stack_push(hStack,i) == FAILURE){
           printf("%d",i);
       }
   }

   stack_destroy(&hStack);
   */
}

// int test_case_is_valid(STACK hMy_stack) {
//   char c;
//   int noc;
//   noc = scanf("%c", &c);
//   while (noc == 1 && c != '\n') {
//     stack_push(hM_stack, int value)
//   }
// }

void clear_keyboard_buffer(void) {
  char c;
  int noc;
  noc = scanf("%c", &c);
  while (noc == 1 && c != '\n') {
    noc = scanf("%c", &c);
  }
}