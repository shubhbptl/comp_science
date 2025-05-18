#include "stack.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;
struct node {
  int length;
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

Status stack_push(STACK hStack, int length) {
  Stack *phStack = (Stack *)hStack;
  Node *temp = (Node *)malloc(sizeof(Node));
  if (temp == NULL) {
    return FAILURE;
  }
  temp->length = length;
  temp->next = phStack->head;
  phStack->head = temp;
  return SUCCESS;
}

/*
Status stack_push(STACK hStack, int length){
        Stack* phStack = (Stack*) hStack;
        Node* temp = (Node*)malloc(sizeof(Node));
        if(temp == NULL){
                return FAILURE;
        }
        temp->lenght = length;
        temp->next = phStack->head;
        phStack->head = temp;
        return SUCCESS;
}
*/
Status stack_pop(STACK hStack) {
  Stack *phStack = (Stack *)hStack;
  if (stack_is_empty(phStack) == TRUE) {
    return FAILURE;
  }
  Node *temp;
  temp = phStack->head;                // point temp to head
  phStack->head = phStack->head->next; // move head to next
  free(temp);                          // free temp
  return SUCCESS;
}

int stack_top(STACK hStack, Status *pStatus) {
  Stack *phStack = (Stack *)hStack;
  if (stack_is_empty(hStack) == TRUE) {
    if (pStatus != NULL) {
      *pStatus = FAILURE;
    }
    return -1337;
  }
  if (pStatus != NULL) {
    *pStatus = SUCCESS;
  }
  return phStack->head->length;
}

Boolean stack_is_empty(STACK hStack) {
  Stack *pStack = (Stack *)hStack;
  return (pStack->head == NULL) ? TRUE : FALSE;
}

void stack_destroy(STACK *phStack) {
  Stack *pStack = (Stack *)*phStack;
  Node *temp;
  while (pStack->head != NULL) {
    temp = pStack->head;               // point temp to head
    pStack->head = pStack->head->next; // move head to next
    free(temp);                        // temp
  }
  free(pStack);    // free whole stack
  *phStack = NULL; // assign to NULL.
}
