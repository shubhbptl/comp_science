#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000000

void print_array(int numbers[], int size);

void vanilla_bubble_sort(int numbers[], int size); // 100000 in 240000 blinks
void bubble_sort(int numbers[], int size);         // 100000 in 20 blinks
void selection_sort(int numbers[], int size);      // 100000 in 5 blinks
void vanilla_insertion_sort(int numbers[], int size);
void insertion_sort_with_shifting(int numbers[], int size);
void insertion_sort(int numbers[], int size); // 100000 3.5 blinks
void shell_sort(int numbers[], int size);     // 10,000,000 5.7 blinks
void heap_sort(int numbers[], int size);

void heapify(int numbers[], int size);
void fix_down(int heap[], int size, int index);
void heap_remove_max(int heap[], int *pSize);

int find_index_of_min(int numbers[], int size, int starting_index);

void my_swap(int *a, int *b);

int main(int argc, char *argv[]) {
  int *numbers;
  int i;

  numbers = (int *)malloc(sizeof(int) * SIZE);
  if (numbers == NULL) {
    printf("Failed to allocate space for array.\n");
    exit(1);
  }

  for (i = 0; i < SIZE; i++) {
    numbers[i] = (rand() << 15) + rand();
    // numbers[i] = i;
  }
  printf("Finished Setup\n");

  heap_sort(numbers, SIZE);
  printf("Done\n");

  // print_array(numbers, SIZE);

  free(numbers);
  return 0;
}

void print_array(int numbers[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d\n", numbers[i]);
  }
}

void vanilla_bubble_sort(int numbers[], int size) {
  int i;
  int j;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - 1; j++) {
      if (numbers[j] > numbers[j + 1]) {
        my_swap(numbers + j, numbers + j + 1);
      }
    }
  }
}

void bubble_sort(int numbers[], int size) {
  int i;
  int j;
  int something_swapped;
  for (i = 0; i < size - 1; i++) {
    something_swapped = 0;
    for (j = 0; j < size - 1 - i; j++) {
      if (numbers[j] > numbers[j + 1]) {
        my_swap(numbers + j, numbers + j + 1);
        something_swapped = 1;
      }
    }
    if (!something_swapped) {
      break;
    }
  }
}

void my_swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selection_sort(int numbers[], int size) {
  int i;
  for (i = 0; i < size - 1; i++) {
    my_swap(&numbers[i], &numbers[find_index_of_min(numbers, size, i)]);
  }
}

int find_index_of_min(int numbers[], int size, int starting_index) {
  int index_of_min = starting_index;
  int i;

  for (i = starting_index + 1; i < size; i++) {
    if (numbers[i] < numbers[index_of_min]) {
      index_of_min = i;
    }
  }
  return index_of_min;
}

void vanilla_insertion_sort(int numbers[], int size) {
  int i;
  int j;
  int temp;
  for (i = 1; i < size; i++) {
    j = i;
    while (j > 0 && numbers[j] < numbers[j - 1]) {
      temp = numbers[j];
      numbers[j] = numbers[j - 1];
      numbers[j - 1] = temp;
      j--;
    }
  }
}

void insertion_sort_with_shifting(int numbers[], int size) {
  int i;
  int j;
  int temp;

  for (i = 1; i < size; i++) {
    j = i;
    temp = numbers[j];
    while (j > 0 && temp < numbers[j - 1]) {
      numbers[j] = numbers[j - 1];
      j--;
    }
    numbers[j] = temp;
  }
}

void insertion_sort(int numbers[], int size) {
  int i;
  int j;
  int temp;

  // sentinel improvement
  my_swap(&numbers[0], &numbers[find_index_of_min(numbers, size, 0)]);

  for (i = 1; i < size; i++) {
    j = i;
    temp = numbers[j];
    while (temp < numbers[j - 1]) {
      numbers[j] = numbers[j - 1];
      j--;
    }
    numbers[j] = temp;
  }
}

void shell_sort(int numbers[], int size) {
  int h = 2;
  int i;
  int j;
  int temp;
  while (h < size / 3) {
    h *= 2;
  }
  h--;

  // h-sort the list with decreasing values of h until and including
  // h==1

  while (h > 0) {
    for (i = h; i < size; i++) {
      j = i;
      temp = numbers[j];
      while (j >= h && temp < numbers[j - h]) {
        numbers[j] = numbers[j - h];
        j -= h;
      }
      numbers[j] = temp;
    }
    h = h / 2;
  }
}

void heap_sort(int numbers[], int size) {
  int i;
  int number_of_iterations = size - 1;
  heapify(numbers, size);
  for (i = 0; i < number_of_iterations; i++) {
    heap_remove_max(numbers, &size);
  }
}

void heapify(int numbers[], int size) {
  int i;
  for (i = size / 2 - 1; i >= 0; i--) {
    fix_down(numbers, size, i);
  }
}

void heap_remove_max(int heap[], int *pSize) {
  int temp;

  temp = heap[0];
  heap[0] = heap[*pSize - 1];
  heap[*pSize - 1] = temp;

  (*pSize)--;

  fix_down(heap, *pSize, 0);
}

void fix_down(int heap[], int size, int index) {
  int index_of_left_child = 2 * index + 1;
  int index_of_right_child = 2 * index + 2;
  int index_of_largest_child;
  int temp;

  if (index_of_left_child < size) // have at least one child
  {
    if (index_of_right_child < size) // have two children
    {
      index_of_largest_child =
          (heap[index_of_left_child] > heap[index_of_right_child])
              ? index_of_left_child
              : index_of_right_child;
    } else // only one child
    {
      index_of_largest_child = index_of_left_child;
    }
    if (heap[index] < heap[index_of_largest_child]) {
      temp = heap[index];
      heap[index] = heap[index_of_largest_child];
      heap[index_of_largest_child] = temp;
      fix_down(heap, size, index_of_largest_child);
    }
  }
}