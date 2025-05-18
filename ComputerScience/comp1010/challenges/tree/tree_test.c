#include <stdio.h>

int tree(int trees[]);

int main(int argc, char *argv[]) {

  int trees[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  printf("%d", tree(trees));
  return 0;
}

int tree(int trees[]) {
  int count = 0;
  int largest = 0;
  int counts[trees[0]];
  for (int i = 0; i < counts[0]; i++) {
    counts[i] = 1;
  }
  for (int i = 1; i <= trees[0]; i++) {
    for (int j = i + 1; j <= 0; j++) {
      if (trees[j] >= largest) {
        largest = trees[j];
        counts[j] = counts[j] + 1;
      }
    }
  }

  for (int i = 0; i <= trees[0]; i++) {
    printf("%d\n", counts[i]);
  }
  return counts[trees[0]];
}