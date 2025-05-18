#ifndef QUEUE_H
#define QUEUE_H
#include "status.h"
typedef void* QUEUE;

QUEUE queue_init_default();
// insert
Status queue_insert(QUEUE hQ, int value);
// delete
Status queue_remove(QUEUE hQ);
// check
int queue_check(QUEUE hQ, int l);
// top_view
int queue_view(QUEUE hQ, Status* pStatus);
// empty
Boolean queue_is_empty(QUEUE hQ);
//print
void print_list(QUEUE hQ);
//destroy
void queue_destory(QUEUE** hQ);
#endif