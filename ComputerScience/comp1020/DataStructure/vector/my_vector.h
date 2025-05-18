#include "status.h"
typedef void* MY_VECTOR;

MY_VECTOR my_vector_init_default(void);

int my_vector_get_size(MY_VECTOR hVector);

int my_vector_capaity(MY_VECTOR hVector);

Status my_vector_pop_back(MY_VECTOR hVector);

int* my_vector_at(MY_VECTOR hVector, int index);

Status my_vector_push_back(MY_VECTOR hVector, int value);

Boolean my_vector_is_empty(MY_VECTOR hVector);

void my_vector_destroy(MY_VECTOR* phVector);
