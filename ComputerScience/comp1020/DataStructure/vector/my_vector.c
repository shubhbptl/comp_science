#include <stdio.h>
#include <stdlib.h>
#include "my_vector.h"



struct my_vector  //Known type
{
	int size;  //number of integers i am holding now
	int capacity;  //number of integers i can hold without resizing.
	int* data;
};

typedef struct my_vector My_vector;

MY_VECTOR my_vector_init_default(void)
{
	//allocate space for the object
	My_vector* pVector;
	pVector = malloc(sizeof(My_vector));
	if (pVector != NULL)
	{
		//set it up into a state that makes sense
		pVector->size = 0;
		pVector->capacity = 1;
		pVector->data = malloc(sizeof(int) * pVector->capacity);
		if (pVector->data == NULL)
		{
			free(pVector);
			return NULL;
		}
	}
	return pVector; 
}

Status my_vector_push_back(MY_VECTOR hVector, int value)
{
	My_vector* pVector = (My_vector*)hVector; //cast to the known type.
	int* temp;
	int i;

	if (pVector->size >= pVector->capacity) //if there is not room then make room
	{
		temp = malloc(sizeof(int) * pVector->capacity * 2);
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < pVector->size; i++)
		{
			temp[i] = pVector->data[i];
		}
		free(pVector->data);
		pVector->data = temp;
		pVector->capacity *= 2;
	}

	pVector->data[pVector->size] = value;
	pVector->size++;
	return SUCCESS;
}

Boolean my_vector_is_empty(MY_VECTOR hVector)
{
	My_vector* pVector = (My_vector*)hVector; //cast to the known type.

	return (pVector->size <= 0) ? TRUE : FALSE;
}

int my_vector_get_size(MY_VECTOR hVector)
{
	My_vector* pVector = (My_vector*)hVector; //cast to the known type.

	return pVector->size;
}

Status my_vector_pop_back(MY_VECTOR hVector)
{
	My_vector* pVector = (My_vector*)hVector; //cast to the known type.

	if (my_vector_is_empty(hVector))
	{
		return FAILURE;
	}

	pVector->size--;
	return SUCCESS;
}

int my_vector_get_capacity(MY_VECTOR hVector)
{
	My_vector* pVector = (My_vector*)hVector; //cast to the known type.

	return pVector->capacity;
}

int* my_vector_at(MY_VECTOR hVector, int index){
	My_vector* pVector = (My_vector*) hVector;
	if(index < 0 || index >= pVector->size){
		return NULL;
	}
	return pVector->data + index; // &(pVector->data[index])
}

void my_vector_destroy(MY_VECTOR* phVector)
{
	My_vector* pVector = (My_vector*)*phVector; //casting to the known type.
	free(pVector->data);
	free(pVector);
	*phVector = NULL;
}