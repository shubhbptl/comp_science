#include <stdio.h>
#include <stdlib.h>

/**********************************************************************
Program: <Filter Number>
Author: <Shubh Patel>
Date: <04/08/25>
Time spent: <2hr>
Purpose: The purpose of this program is to put user input into dynamic array,
then sort the array, remove the duplicated, then print the result.
***********************************************************************/

#define SIZE 2000000000
struct array {
  int size;
  int capacity;
  int *data;
};
typedef struct array Array;
typedef void *ARRAY;

ARRAY init_array(void);
void insert_to_array(ARRAY array, int value);
void clear_keyboard_buffer(void);
void my_swap(int *a, int *b);
void sort_number(ARRAY array);
void remove_duplicate(ARRAY array);
int main(int argc, char *argv[]) {
  Array *arr = init_array();
  int result = 0;
  int size = 0;
  if (arr == NULL) {
    printf("Failed to allocate space.\n");
    exit(1);
  }
  while (scanf("%d", &result) == 1 && result != -1) {
    clear_keyboard_buffer();
    insert_to_array(arr, result);
  }
  sort_number(arr);
  remove_duplicate(arr);
  free(arr->data);
  free(arr);
  return 0;
}

ARRAY init_array(void) {
  Array *p_Array;
  p_Array = (Array *)malloc(sizeof(Array));
  if (p_Array != NULL) {
    p_Array->capacity = 8;
    p_Array->size = 0;
    p_Array->data = (int *)malloc(sizeof(int) * p_Array->capacity);
    if (p_Array->data == NULL) {
      free(p_Array);
      return NULL;
    }
  }
  return p_Array;
}
void insert_to_array(ARRAY array, int value) {
  Array *p_Array = (Array *)array;
  int *temp;
  if (p_Array->size >= p_Array->capacity) {
    temp = (int *)malloc(sizeof(int) * p_Array->capacity * 2);
    if (temp == NULL) {
      exit(1);
    }
    for (int i = 0; i < p_Array->size; i++) {
      temp[i] = p_Array->data[i];
    }
    free(p_Array->data);
    p_Array->data = temp;
    p_Array->capacity *= 2;
  }
  p_Array->data[p_Array->size] = value;
  p_Array->size++;
}

void sort_number(ARRAY array) {
  Array *p = (Array *)array;
  int *a = p->data;
  int n = p->size;

  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[min_idx]) {
        min_idx = j;
      }
    }
    my_swap(&a[i], &a[min_idx]);
  }
}
void remove_duplicate(ARRAY array) {
  Array *p = (Array *)array;
  int *a = p->data;
  int n = p->size;

  if (n <= 0)
    return;

  int last = a[0];
  printf("%d\n", last);

  for (int i = 1; i < n; i++) {
    if (a[i] != last) {
      last = a[i];
      printf("%d\n", last);
    }
  }
}

void my_swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void clear_keyboard_buffer(void) {
  char c;
  int noc;
  noc = scanf("%c", &c);
  while (noc == 1 && c != '\n') {
    scanf("%c", &c);
  }
}
