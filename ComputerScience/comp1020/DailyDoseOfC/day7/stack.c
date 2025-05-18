#include "stack.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;
struct node {
  char value;
  Node *next;
};
struct stack { // known type
  Node *head;
};
typedef struct stack Stack;

STACK stack_init_default() {
  Stack *pStack = (Stack *)malloc(sizeof(Stack));
  if (pStack != NULL) {
    pStack->head = NULL;
  }
  return pStack;
}

Status stack_push(STACK hStack, char value) {
  Stack *phStack = (Stack *)hStack;
  Node *temp = (Node *)malloc(sizeof(Node));
  if (temp == NULL) {
    return FAILURE;
  }
  temp->value = value;
  temp->next = phStack->head;
  phStack->head = temp;
  return SUCCESS;
}

Status stack_pop(STACK hStack) {
  Stack *phStack = (Stack *)hStack;
  if (stack_is_empty(phStack) == TRUE) {
    return FAILURE;
  }
  Node *temp;
  temp = phStack->head;
  phStack->head = phStack->head->next;
  free(temp);
  return SUCCESS;
}

char stack_top(STACK hStack, Status *pStatus) {
  Stack *phStack = (Stack *)hStack;
  if (stack_is_empty(hStack) == TRUE) {
    if (pStatus != NULL) {
      *pStatus = FAILURE;
    }
    return 0;
  }
  if (pStatus != NULL) {
    *pStatus = SUCCESS;
  }
  return phStack->head->value;
}

Boolean stack_is_empty(STACK hStack) {
  Stack *pStack = (Stack *)hStack;
  return (pStack->head == NULL) ? TRUE : FALSE;
}

int test_case_is_valid(STACK hStack) {
    Stack *pStack = (Stack *)hStack;
    char c;
    int noc;
    noc = scanf("%c", &c);
    while (noc == 1 && c != '\n') {
      if (c == '(' || c == '[') {
        stack_push(pStack, c);
      } else if ((c == ')' && stack_top(pStack, NULL) == '(') ||
                 (c == ']' && stack_top(pStack, NULL) == '[')) {
        stack_pop(pStack);
    } else if (c == ')' || c == ']') {
        while(getchar() != '\n')
        ;
            return 0;
    }
    noc = scanf("%c", &c);
}
    int result = (stack_is_empty(pStack) == TRUE) ? 1 : 0;
    return result;
  }
void clear_keyboard_buffer(void) {
  char c;
  int noc;
  noc = scanf("%c", &c);
  while (noc == 1 && c != '\n') {
    noc = scanf("%c", &c);
  }
}

void stack_destroy(STACK *phStack) {
  Stack *pStack = (Stack *)*phStack;
  Node *temp;
  while (pStack->head != NULL) {
    temp = pStack->head;
    pStack->head = pStack->head->next;
    free(temp);
  }
  free(pStack);
  *phStack = NULL;
}
