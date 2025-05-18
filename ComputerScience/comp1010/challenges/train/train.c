#include <stdio.h>

int train_sort(int arr[], int size);

int main(int argc, char *argv[]) {
  int arr[] = {5, 4, 3, 2, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Optimal train swapping takes %d swaps.\n", train_sort(arr, size));
}

int train_sort(int arr[], int size) {
  int swap = 0;
  if (size == 1 && size != 0) {
    return 1;
  }
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swap++;
      }
    }
  }

  return swap;
}