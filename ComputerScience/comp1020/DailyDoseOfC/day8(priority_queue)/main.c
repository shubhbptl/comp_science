#include "priority_queue.h"
#include <stdio.h>
int main(int argc, char *argv[]) {
  PRIORITY_QUEUE Queue;
  Queue = priority_queue_init_default();
  for (int i = 0; i < 10; i++) {
    priority_queue_insert(Queue, i, i * 10);
  }
  for (int i = 0; i < 10; i++) {
    printf("value: %d\n", priority_queue_front(Queue, NULL));
    priority_queue_service(Queue);
  }

  if (priority_queue_is_empty(Queue) == TRUE) {
    printf("empty");
  }
  priority_queue_destroy(&Queue);
  return 0;
}
