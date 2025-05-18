#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>
struct priority_queue {
  int *key;
  int *value;
  int size;
  int capactiy;
};
typedef struct priority_queue Priority_Queue;
void fix_up(PRIORITY_QUEUE hQueue, int index);
void fix_down(PRIORITY_QUEUE hQueue, int size, int index);
PRIORITY_QUEUE priority_queue_init_default(void) {
  Priority_Queue *pQ = (Priority_Queue *)malloc(sizeof(Priority_Queue));
  if (pQ != NULL) {
    pQ->size = 0;
    pQ->capactiy = 1;
    pQ->key = (int *)malloc(sizeof(int) * pQ->capactiy);
    pQ->value = (int *)malloc(sizeof(int) * pQ->capactiy);
    if (pQ->key == NULL || pQ->value == NULL) {
      if (pQ->key)
        free(pQ->key);
      if (pQ->value)
        free(pQ->value);
      free(pQ);
      return NULL;
    }
  }
  return pQ;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level,
                             int data_item) {
  Priority_Queue *phQueue = (Priority_Queue *)hQueue;
  if (phQueue->size >= phQueue->capactiy) {
    int *temp_data;
    int *temp_key;
    int new_capacity = phQueue->size + 1;
    temp_data = (int *)malloc(sizeof(int) * new_capacity);
    if (temp_data == NULL) {
      return FAILURE;
    }
    temp_key = (int *)malloc(sizeof(int) * new_capacity);
    if (temp_key == NULL) {
      return FAILURE;
    }
    for (int i = 0; i < phQueue->size; i++) {
      temp_data[i] = phQueue->value[i];
      temp_key[i] = phQueue->key[i];
    }
    free(phQueue->value);
    phQueue->value = temp_data;
    free(phQueue->key);
    phQueue->key = temp_key;
    phQueue->capactiy = new_capacity;
  }
  phQueue->value[phQueue->size] = data_item;
  phQueue->key[phQueue->size] = priority_level;
  phQueue->size++;
  fix_up(phQueue, phQueue->size - 1);

  return SUCCESS;
}
void fix_up(PRIORITY_QUEUE hQueue, int index) {
  Priority_Queue *phQueue = (Priority_Queue *)hQueue;
  int index_of_parent = (index - 1) / 2;
  int temp_key;
  int temp_data;
  if (index > 0) {
    if (phQueue->key[index] > phQueue->key[index_of_parent]) {
      temp_key = phQueue->key[index];
      temp_data = phQueue->value[index];
      phQueue->key[index] = phQueue->key[index_of_parent];
      phQueue->value[index] = phQueue->value[index_of_parent];
      phQueue->key[index_of_parent] = temp_key;
      phQueue->value[index_of_parent] = temp_data;
      fix_up(phQueue, index_of_parent);
    }
  }
}
void fix_down(PRIORITY_QUEUE hQueue, int size, int index) {
  Priority_Queue *phQueue = (Priority_Queue *)hQueue;
  int index_of_left = (2 * index) + 1;
  int index_of_right = (2 * index) + 2;
  int index_of_largest;
  int temp_data;
  int temp_key;
  if (index_of_left < phQueue->size) {
    index_of_largest =
        (phQueue->key[index_of_left] > phQueue->key[index_of_right])
            ? index_of_left
            : index_of_right;
  } else {
    index_of_largest = index_of_left;
  }

  if (phQueue->key[index] < phQueue->key[index_of_largest]) {
    temp_key = phQueue->key[index];
    temp_data = phQueue->value[index];
    phQueue->key[index] = phQueue->key[index_of_largest];
    phQueue->value[index] = phQueue->value[index_of_largest];
    phQueue->key[index_of_largest] = temp_key;
    phQueue->value[index_of_largest] = temp_data;
    fix_down(phQueue, phQueue->size, index_of_largest);
  }
}

Status priority_queue_service(PRIORITY_QUEUE hQueue) {
  Priority_Queue *phQueue = (Priority_Queue *)hQueue;
  if (priority_queue_is_empty(phQueue) == TRUE) {
    return FAILURE;
  }
  phQueue->key[0] = phQueue->key[phQueue->size - 1];
  phQueue->value[0] = phQueue->value[phQueue->size - 1];

  phQueue->size--;
  fix_down(phQueue, phQueue->size, 0);
  return SUCCESS;
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue) {
  Priority_Queue *phQueue = (Priority_Queue *)hQueue;
  return (phQueue->size <= 0) ? TRUE : FALSE;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status *pStatus) {
  Priority_Queue *phQueue = (Priority_Queue *)hQueue;
  if (priority_queue_is_empty(phQueue) == TRUE) {
    if (pStatus != NULL) {
      *pStatus = FAILURE;
    }
    return -1337; // Not Elite
  }
  if (pStatus != NULL) {
    *pStatus = SUCCESS;
  }
  return phQueue->value[0];
}

void priority_queue_destroy(PRIORITY_QUEUE *phQueue) {
  Priority_Queue *pQ = (Priority_Queue *)*phQueue;
  free(pQ->value);
  free(pQ->key);
  free(pQ);
  *phQueue = NULL;
}