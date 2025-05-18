#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "status.h"
struct node;
typedef struct node Node;
struct node{
    int data;
    Node* next;
};

struct queue{
    Node* head;
    Node* tail;
};
typedef struct queue Queue;

QUEUE queue_init_default(void){
    Queue* pQ = (Queue*)malloc(sizeof(Queue));
    if(pQ != NULL){
        pQ->head = NULL;
        pQ->tail = NULL;
    }
    return pQ;
}

void print_list(QUEUE hQ){
    Queue* pQ = (Queue*) hQ;
    Node* curr = pQ->head;
    while(curr != NULL){
        printf("%d->",curr->data);
        curr = curr->next;
    }
    printf("NULL");
}

Boolean queue_is_empty(QUEUE hQ){
    Queue* pQ = (Queue*) hQ;
    return (pQ->head == NULL) ? TRUE : FALSE;
}
Status queue_insert(QUEUE hQ, int value){
    Queue* pQ = (Queue*) hQ;
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL){
        return FAILURE;
    }
    temp->data = value;
    temp->next = NULL;
    if(pQ->head == NULL){
        pQ->head = temp;
        pQ->tail = temp;
    }else{
        pQ->tail->next = temp;
        pQ->tail = temp;
    }
    return SUCCESS;
}

int queue_view(QUEUE hQ, Status* pStatus){
    Queue* pQ = (Queue*) hQ;
    if(queue_is_empty( pQ) == TRUE){
        if(pStatus != NULL){
            return FAILURE;
        }
        return -1337; // opposite of elite
    }
    if(pStatus != NULL){
        return SUCCESS;
    }
    return pQ->head->data;
    
}
Status queue_remove(QUEUE hQ){
    Queue* pQ = (Queue*) hQ;
    Node* temp;
    if(pQ->head == NULL){
        return FAILURE;
    }
    temp = pQ->head;
    pQ->head = pQ->head->next;
    free(temp);
    return SUCCESS;
}
void queue_destory(QUEUE** hQ){
    Queue* pQ = (Queue*) *hQ;
    Node* temp;
    while(pQ->head != NULL){
        temp = pQ->head;
        pQ->head = pQ->head->next;
        free(temp);
    }
    free(pQ); pQ = NULL;
}